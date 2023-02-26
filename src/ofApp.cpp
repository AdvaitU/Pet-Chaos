#include "ofApp.h"

//----------------------------------------------------------------------------------------------------
void ofApp::setup(){

	red.set(5.0, 5.0, 0);           
	blue.set(5.0, 5.0, 80);
	green.set(5.0, 5.0, 80);


}

//-----------------------------------------------------------------------------------------------------

void ofApp::update(){
	
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }

}

//-----------------------------------------------------------------------------------------------------

void ofApp::draw(){

    ofBackgroundGradient((red.infection, green.infection, blue.infection), (0, 0, 0), OF_GRADIENT_CIRCULAR);

    
    para1 += 50;
    para2 += 80;
    makeParticle(ofNoise(para1), ofNoise(para2));

    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }

	

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

    makeParticle(mouseX, mouseY);

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

void ofApp::makeParticle(int i1, int i2)
{

    particle newParticle(i1, i2, hue);
    particles.push_back(newParticle);

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
    // destructor
}
//--------------------------------------------------------------

void particle::update() {
    // update the particle x,y position by incrementing each by the velocity vx and vy
    position += direction;
    direction += force;
    if (size > 1) {
        size -= 0.07;
    }
    float brightness = color.getBrightness();
    float myHue = color.getHue();

    if (brightness > 20) {
        // color.setBrightness( brightness -=0.5 );
        color.setHue(myHue -= 0.5);

    }
}

//--------------------------------------------------------------

void particle::draw() {
    ofSetColor(color);
    ofDrawCircle(position, size);
}
