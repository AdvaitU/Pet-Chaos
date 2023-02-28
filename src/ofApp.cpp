#include "ofApp.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------------------------------------
void ofApp::setup(){

	red.set(0, 0, 0, 100, 200);           
	green.set(0, 0, 0, 800, 150);
    blue.set(0, 0, 0, 500, 450);

    red.loadImage();
    green.loadImage();
    blue.loadImage();

    startTime = ofGetElapsedTimeMillis();
}

//-----------------------------------------------------------------------------------------------------

void ofApp::update(){
	
    for (int i = 0; i < redParticles.size(); i++) {
        redParticles[i].update(red.hunger, red.chaos);
        greenParticles[i].update(green.hunger, blue.chaos);
        blueParticles[i].update(blue.hunger, green.chaos);
    }

}

//-----------------------------------------------------------------------------------------------------

void ofApp::draw(){

    ofBackgroundGradient((0,0,0),(10,10,10),OF_GRADIENT_LINEAR);

    //para1 += 0.2;
    //para2 += 0.2;
    //para3 += 0.2;

    //cout << red.hunger << " " << green.hunger << " " << blue.hunger << endl;
    //cout << red.chaos << " " << green.chaos << " " << blue.chaos << endl;
    cout << red.infection << " " << green.infection << " " << blue.infection << endl;
    
    particle newRedParticle(red.initX + ofRandom(50), red.initY + ofRandom(50), 0);
    redParticles.push_back(newRedParticle);

    particle newGreenParticle(green.initX + ofRandom(50), green.initY + ofRandom(50), 0);
    greenParticles.push_back(newGreenParticle);

    particle newBlueParticle(blue.initX + ofRandom(50), blue.initY + ofRandom(50), 0);
    blueParticles.push_back(newBlueParticle);

    currTime = ofGetElapsedTimeMillis() - startTime;   // Noting down current time as value returned by function minus startTime
    if (currTime >= 5000) {                            // If 1.5 seconds have passed
        red.tickAnimal();                              // Run the tickAnimal() function from the Animal class
        green.tickAnimal();
        blue.tickAnimal();
        startTime = ofGetElapsedTimeMillis();          // Reset startTime
    }

    for (int i = 0; i < redParticles.size(); i++) {
        redParticles[i].draw(255, 0, 0);
        greenParticles[i].draw(0, 255, 0);
        blueParticles[i].draw(0, 0, 255);
    }

    red.statusAnimal();
    green.statusAnimal();
    blue.statusAnimal();
    movePet();

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

void ofApp::infection(int i, int r, int g, int b)
{
    ofNoFill();
    ofBeginShape();
    for (int j = 0; j < i/2; j++) {
        
        ofSetLineWidth(i * 0.1);
        ofSetColor(r, g, b);
        //ofDrawLine(ofRandom(1000), ofRandom(1000), ofRandom(1000) + 300, ofRandom(1000) + 300);
        ofVertex(ofRandom(1000), ofRandom(1000));
        
    }
    ofEndShape();
    ofFill();

}

void ofApp::movePet()
{


    if (red.i) {
        red.initX += ofRandom(1, 8);
        red.initY += ofRandom(-1, 8);
        red.sad.draw(red.initX, red.initY);
        if (ofRandom(100) > 96) {
            red.initX = 100;
            red.initY = 200;
        }
    }
    else if (red.infection > 5 && red.infection < 11) {
        red.happy.draw(red.initX, red.initY);
    }
    else {
        red.neutral.draw(red.initX, red.initY);
    }

    if (green.i) {
        green.initX += ofRandom(-8, +1);
        green.initY += ofRandom(-1, +8);
        green.sad.draw(green.initX, green.initY);
        if (ofRandom(100) > 96) {
            green.initX = 800;
            green.initY = 150;
        }
    }
    else if (green.infection > 5 && green.infection < 11) {
        green.happy.draw(green.initX, green.initY);
    }
    else {
        green.neutral.draw(green.initX, green.initY);
    }

    if (blue.i) {
        blue.initX += ofRandom(-8, 8);
        blue.initY += ofRandom(-8, +1);
        blue.sad.draw(blue.initX, blue.initY);
        if (ofRandom(100) > 96) {
            blue.initX = 500;
            blue.initY = 450;
        }

    }
    else if (blue.infection > 5 && blue.infection < 11) {
        blue.happy.draw(blue.initX, blue.initY);
    }
    else {
        blue.neutral.draw(blue.initX, blue.initY);
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
    ofSetColor(r, g, b, 120);
    ofDrawEllipse(position, size, size + ofRandom(10));
}
