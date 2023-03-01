#include "ofApp.h"
#include <iostream>   // Only for debugging
using namespace std;

//----------------------------------------------------------------------------------------------------
void ofApp::setup(){

	red.set(0, 0, 0, 100, 200);       // Setting up initial values of all Animal class objects    
	green.set(0, 0, 0, 800, 150);
    blue.set(0, 0, 0, 500, 450);

    red.loadImage("c1h-01.png", "c1n-01.png", "c1s-01.png");    // Loading up images for all Animal class objects
    green.loadImage("c2h-01.png", "c2n-01.png", "c2s-01.png");
    blue.loadImage("c3h-01.png", "c3n-01.png", "c3s-01.png");

    bg.load("bg2-01.png");         // Loading background image

    startTime = ofGetElapsedTimeMillis();   // Saving time at the start of the programme
}

//-----------------------------------------------------------------------------------------------------

void ofApp::update(){
	
    for (int i = 0; i < redParticles.size(); i++) {             // Run the update() function from the Particle class for all Particle objects
        redParticles[i].update(red.hunger, red.chaos);
        greenParticles[i].update(green.hunger, blue.chaos);
        blueParticles[i].update(blue.hunger, green.chaos);
    }

}

//-----------------------------------------------------------------------------------------------------

void ofApp::draw(){

    ofBackgroundGradient((0,0,0),(10,10,10),OF_GRADIENT_LINEAR);   // Background gradient - Replace with Image

    //cout << red.hunger << " " << green.hunger << " " << blue.hunger << endl;     // Debugging
    //cout << red.chaos << " " << green.chaos << " " << blue.chaos << endl;
    //cout << red.infection << " " << green.infection << " " << blue.infection << endl;
    
    particle newRedParticle(red.initX + ofRandom(50), red.initY + ofRandom(50), 0);    // Create new particles for all three instances and push them into the respective vectors
    redParticles.push_back(newRedParticle);

    particle newGreenParticle(green.initX + ofRandom(50), green.initY + ofRandom(50), 0);
    greenParticles.push_back(newGreenParticle);

    particle newBlueParticle(blue.initX + ofRandom(50), blue.initY + ofRandom(50), 0);
    blueParticles.push_back(newBlueParticle);

    currTime = ofGetElapsedTimeMillis() - startTime;   // Noting down current time as value returned by function minus startTime
    if (currTime >= 5000) {                            // If 5 seconds have passed
        red.tickAnimal();                              // Run the tickAnimal() function from the Animal class
        green.tickAnimal();
        blue.tickAnimal();
        startTime = ofGetElapsedTimeMillis();          // Reset startTime
    }

    for (int i = 0; i < redParticles.size(); i++) {     // Run draw() function from Particle class for all instances
        redParticles[i].draw(255, 0, 0);
        greenParticles[i].draw(0, 255, 0);
        blueParticles[i].draw(0, 0, 255);
    }

    red.statusAnimal();        // Update status booleans
    green.statusAnimal();
    blue.statusAnimal();

    movePet();                 // Check for movement and the right image

}

//--------------------------------------------------------------


void ofApp::keyPressed(int key){

    switch (key) {
    case 'q':
        red.offerBlood();
        break;
    case 'w':
        red.sacrificeAnimal();
        break;
    case 'e':
        red.usePotion();
        break;
    case 'a':
        green.offerBlood();
        break;
    case 's':
        green.sacrificeAnimal();
        break;
    case 'd':
        green.usePotion();
        break;
    case 'z':
        blue.offerBlood();
        break;
    case 'x':
        blue.sacrificeAnimal();
        break;
    case 'c':
        blue.usePotion();
        break;
    case 'p':
        startGame = false;
        break;
    case 'l':
        ofToggleFullscreen();
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

void ofApp::movePet()
{

    if (red.i) {
        red.initX += ofRandom(1, 8);
        red.initY += ofRandom(-1, 8);
        red.sad.draw(red.initX - 150, red.initY - 300);
        if (ofRandom(100) > 96) {
            red.initX = 100;
            red.initY = 200;
        }
    }
    else if (red.infection > 5 && red.infection < 11) {
        red.neutral.draw(red.initX - 120, red.initY - 100);
        red.i = false;
    }
    else {
        red.happy.draw(red.initX - 120, red.initY - 120);
        red.i = false;
    }

    if (green.i) {
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

    if (blue.i) {
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

}




//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// -------------------------- PARTICLE SYSTEM FUNCTIONS ----------------------------------------------------------------------------

particle::particle(int startX, int startY, int hue) {
    // this is the constructor routine, called when we make a new object of our particle class defined in the header
    position = glm::vec2(startX, startY);
    force = glm::vec2(0, 0.02);
    direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
    size = 30;
    color.setHsb(hue, 255, 255, 200);
}
//--------------------------------------------------------------

particle::~particle() {
    // Empty Destructor
}
//--------------------------------------------------------------


void particle::update(float input1, float input2) {
    // update the particle x,y position by incrementing each by the velocity vx and vy
    position += direction * input1;
    direction += force;
    if (size > 1) {
        size -= input2 * 0.1;
    }
    float brightness = color.getBrightness();
    float myHue = color.getHue();

    if (brightness > 20) {
        // color.setBrightness( brightness -=0.5 );
        color.setHue(myHue -= 0.5);

    }
}

//--------------------------------------------------------------

void particle::draw(int r, int g, int b) {
    ofSetColor(r, g, b);
    ofDrawEllipse(position, size, size + ofRandom(10));
}
