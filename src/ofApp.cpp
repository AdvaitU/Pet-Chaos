#include "ofApp.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------------------------------------
void ofApp::setup(){

	red.set(0, 0, 0);           
	blue.set(0, 0, 0);
	green.set(0, 0, 0);

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

    //para1 += 1;
    //para2 += 1;
    //para3 += 1;

    cout << red.hunger << " " << green.hunger << " " << blue.hunger << endl;
    
    particle newRedParticle(100 + ofRandom(para1), 100 + ofRandom(para1), 0);
    redParticles.push_back(newRedParticle);

    particle newGreenParticle(500 + ofRandom(para2), 250 + ofRandom(para2), 0);
    greenParticles.push_back(newGreenParticle);

    particle newBlueParticle(600 + ofRandom(para3), 150 + ofRandom(para3), 0);
    blueParticles.push_back(newBlueParticle);

    currTime = ofGetElapsedTimeMillis() - startTime;   // Noting down current time as value returned by function minus startTime
    if (currTime >= 3000) {                            // If 1.5 seconds have passed
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

    infection(red.infection, 150, 0, 0);
    infection(green.infection, 0, 150, 0);
    infection(blue.infection, 0, 0, 150);

	

}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){

	

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

    for (int j = 0; j < i/2; j++) {
        ofSetLineWidth(i * 0.1);
        ofSetColor(r, g, b);
        ofDrawLine(ofRandom(1000), ofRandom(1000), ofRandom(1000) + 300, ofRandom(1000) + 300);
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
