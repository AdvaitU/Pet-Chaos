#include "ofApp.h"
#include <iostream>   // Only for debugging
using namespace std;  // For cout

//------------------------------------------------------------------------- SETUP FUNCTION ------------------------------------------------------------------------------//


void ofApp::setup(){

	red.set(0, 0, 0, 100, 200);       // Setting up initial values of all Animal class objects    
	green.set(0, 0, 0, 800, 150);     // In order, sets hunger, chaos, infection, initX, and initY values
    blue.set(0, 0, 0, 500, 450);

    red.loadImage("c1h-01.png", "c1n-01.png", "c1s-01.png");    // Loading up images for all Animal class objects
    green.loadImage("c2h-01.png", "c2n-01.png", "c2s-01.png");  // In order, loads into gree.happy, green.neutral and green.sad ofImage variables
    blue.loadImage("c3h-01.png", "c3n-01.png", "c3s-01.png");

    ss.load("splash_screen-01.png");         // Loading background image
    bg.load("bg3-01.png");                   // Image credits to u/_onkardesai_ (https://www.reddit.com/r/Maya/comments/sy5q16/the_attic_my_new_cg_lighting_work_i_was_looking/)

    startTime = ofGetElapsedTimeMillis();   // Saving time at the start of the programme
}


//------------------------------------------------------------------------ UPDATE FUNCTION -----------------------------------------------------------------------------//


void ofApp::update(){
	
    for (int i = 0; i < redParticles.size(); i++) {             // Run the update() function from the Particle class for all Particle objects
        redParticles[i].update(red.hunger, red.chaos);          // Takes hunger and chaos values and uses them to multiply values in code
        greenParticles[i].update(green.hunger, blue.chaos);
        blueParticles[i].update(blue.hunger, green.chaos);
    }

}


//------------------------------------------------------------------------- DRAW FUNCTION ------------------------------------------------------------------------------//


void ofApp::draw(){

    // BACKGROUND ----------------------------------------------------------------------------------------------------
    //ofBackground(0);
    bg.draw(0, 0, 1024, 768);   // Background



    // UNCOMMENT FOR DEBUGGING AND ADJUSTING GAME PARAMETERS ---------------------------------------------------------
    //cout << red.hunger << " " << green.hunger << " " << blue.hunger << endl;     // Debugging
    //cout << red.chaos << " " << green.chaos << " " << blue.chaos << endl;
    //cout << red.infection << " " << green.infection << " " << blue.infection << endl;
    

    // CREATING NEW PARTICLES EVERY FRAME ----------------------------------------------------------------------------
    particle newRedParticle(red.initX + ofRandom(50), red.initY + ofRandom(50), 0);    // Create new particles for all three instances and push them into the respective vectors
    redParticles.push_back(newRedParticle);

    particle newGreenParticle(green.initX + ofRandom(50), green.initY + ofRandom(50), 0);
    greenParticles.push_back(newGreenParticle);

    particle newBlueParticle(blue.initX + ofRandom(50), blue.initY + ofRandom(50), 0);
    blueParticles.push_back(newBlueParticle);


    // TIMER AND TICK ---------------------------------------------------------------------------------------------------
    // Change '5000' to change tick time in milliseconds
    currTime = ofGetElapsedTimeMillis() - startTime;   // Noting down current time as value returned by function minus startTime
    if (currTime >= 5000) {                            // If 5 seconds have passed
        red.tickAnimal();                              // Run the tickAnimal() function from the Animal class
        green.tickAnimal();
        blue.tickAnimal();
        startTime = ofGetElapsedTimeMillis();          // Reset startTime
    }


    // PARTICLE.DRAW FUNCTONS FOR ALL PARTICLES -------------------------------------------------------------------------
    for (int i = 0; i < redParticles.size(); i++) {     // Run draw() function from Particle class for all instances
        redParticles[i].draw(139, 69, 19);
        greenParticles[i].draw(255, 140, 0);
        blueParticles[i].draw(255, 215, 0);
    }


    // STATUS BOOLEANS SWITCH --------------------------------------------------------------------------------------------
    red.statusAnimal();        // Update status booleans
    green.statusAnimal();
    blue.statusAnimal();


    // SET COLOUR TO WHITE FULL ALPHA AND MOVE ---------------------------------------------------------------------------
    ofSetColor(255, 255, 255, 255);   // Set colour fill to white, full alpha
    movePet();                        // Check for movement from initial position and the display right image


    // SPLASH SCREEN OVERLAY CHECK ---------------------------------------------------------------------------------------
    if (startGame) {                                // Bool is true if the game has launched and changes to false after 'P' is pressed.
        ss.draw(25, 20, 1024 * 0.95, 768 * 0.95);   // Draws the Splash Screen image at 95% size of the screen centred
    }                                               // Lays out instructions to the game

}


// -------------------------------------------------------------------------- END OF DRAW ------------------------------------------------------------------------------//





//------------------------------------------------------------------- START OF OBSERVER FUNCTIONS ----------------------------------------------------------------------//


void ofApp::keyPressed(int key){

    switch (key) {                      // Switch according to key
    case 'q':                           // Red Buttons
        red.offerBlood();
        break;
    case 'w':
        red.sacrificeAnimal();
        break;
    case 'e':
        red.usePotion();
        break;

    case 'a':                          // Green Buttons
        green.offerBlood();
        break;
    case 's':
        green.sacrificeAnimal();
        break;
    case 'd':
        green.usePotion();
        break;

    case 'z':                         // Blue Buttons
        blue.offerBlood();
        break;
    case 'x':
        blue.sacrificeAnimal();
        break;
    case 'c':
        blue.usePotion();
        break;

    case 'p':                                    // Other Buttons

        startGame = false;                       // Set startGame as false

        red.set(0, 0, 0, 100, 200);              // Setting up initial values of all Animal class objects    
        green.set(0, 0, 0, 800, 150);
        blue.set(0, 0, 0, 500, 450);

        startTime = ofGetElapsedTimeMillis();    // Saving time at the start of the programme

        redParticles.clear();                    // Remove all elements added to the particle vectors to restart from the beginning
        greenParticles.clear();
        blueParticles.clear();

        break;

    case 'l':
        ofToggleFullscreen();              // Toggle Full screen
        break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

// ------------------------------------------------------------------- ANIMAL FUNCTIONS --------------------------------------------------------------------------------//
void ofApp::movePet()
{
    //--------------------------------------------------------------------------

    if (red.i) {                                           // If red's infection is above threshold
        red.initX += ofRandom(1, 8);                       // Move along X axis random number
        red.initY += ofRandom(-1, 8);                      // Move along Y axis random number
        red.sad.draw(red.initX - 150, red.initY - 300);    // Draw sad face
        if (ofRandom(100) > 96) {                          // 4% chance
            red.initX = 100;                               // Move back to initial position
            red.initY = 200;
        }
    }
    else if (red.infection > 5 && red.infection < 11) {    // If between defined range
        red.neutral.draw(red.initX - 120, red.initY - 100);   // Draw neutral face
        red.i = false;
    }
    else {                                                 // Else
        red.happy.draw(red.initX - 120, red.initY - 120);  // Draw happy face
        red.i = false;
    }

    //--------------------------------------------------------------------------

    if (green.i) {                                         // Same for green
        green.initX += ofRandom(-8, +1);
        green.initY += ofRandom(-1, +8);
        green.sad.draw(green.initX - 160, green.initY - 130);
        if (ofRandom(100) > 96) {
            green.initX = 800;
            green.initY = 150;
        }
    }
    else if (green.infection > 5 && green.infection < 11) {
        green.neutral.draw(green.initX - 200, green.initY - 100);
        green.i = false;
    }
    else {
        green.happy.draw(green.initX - 70, green.initY - 150);
        green.i = false;
    }

    //--------------------------------------------------------------------------

    if (blue.i) {                                         // Same for blue
        blue.initX += ofRandom(-8, 8);
        blue.initY += ofRandom(-8, +1);
        blue.sad.draw(blue.initX - 130, blue.initY - 160);
        if (ofRandom(100) > 96) {
            blue.initX = 500;
            blue.initY = 450;
        }

    }
    else if (blue.infection > 5 && blue.infection < 11) {
        blue.neutral.draw(blue.initX - 140, blue.initY);
        blue.i = false;
    }
    else {
        blue.happy.draw(blue.initX - 120, blue.initY - 200);
        blue.i = false;
    }

    //--------------------------------------------------------------------------

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// ------------------------------------------------------------------------ PARTICLE SYSTEM FUNCTIONS -------------------------------------------------------------------//

particle::particle(int startX, int startY, int hue) {

    // This is the constructor routine, called when we make a new object of our particle class defined in the header

    position = glm::vec2(startX, startY);        // Set position
    force = glm::vec2(0, 0.02);                  // Set force
    direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));   // Set direction as random between -0.2 and 0.2
    size = 30;                         // Size of particle
    color.setHsb(hue, 255, 255, 200);  // Default colour
}
//--------------------------------------------------------------

particle::~particle() {
    // Empty Destructor
}
//--------------------------------------------------------------


void particle::update(float input1, float input2) {

    // Update the particle x,y position by incrementing each by the velocity vx and vy

    position += direction * input1;  // Multiplied by hunger
    direction += force;
    if (size > 1) {
        size -= input2 * 0.1;      // Reduce the size of particle by 10% of chaos factor every frame
    }
    float brightness = color.getBrightness();
    float myHue = color.getHue();

    if (brightness > 20) {
        // color.setBrightness( brightness -=0.5 );
        color.setHue(myHue -= 0.5);             // Reduce hue every frame

    }
}

//--------------------------------------------------------------

void particle::draw(int r, int g, int b) {
    ofSetColor(r, g, b, 150);                               // Set colour as input colour
    ofDrawEllipse(position, size, size + ofRandom(10));     // Draw ellipses of random size
}


// ------------------------------------------------------------------------------ END OF CODE ---------------------------------------------------------------------------//
