#include "ofApp.h"

//----------------------------------------------------------------------------------------------------
void ofApp::setup(){

	animal.set(5.0, 5.0, 4.0);                   // Setting initial values

	hungryCat.load("hungryCat-01.jpg");          // Loading up images
	happyCat.load("happyCat-01.jpg");
	toBePetCat.load("toBePetCat-01.jpg");
	sadCat.load("sadCat-01.jpg");
	sleepingCat.load("sleepingCat-01.jpg");
	thirstyCat.load("thirstyCat-01.jpg");
	exhaustedCat.load("exhaustedCat-01.jpg");

	font.load("Cascadia.ttf", 21);              // Loading font file
	instructions.load("Cascadia.ttf", 16);

	startTime = ofGetElapsedTimeMillis();       // Noting down initial time at the start of the programme in milliseconds

}

//-----------------------------------------------------------------------------------------------------

void ofApp::update(){
	// EMPTY ---------------------------------------------------
}

//-----------------------------------------------------------------------------------------------------

void ofApp::draw(){


	float imgWidth = happyCat.getWidth() / 2;     // Floats for image width and height for drawing
	float imgHeight = happyCat.getHeight() / 2;

	instructions.drawString("Press 'Q' to feed the cat, 'E' to give it water\n    and 'T' to pet it. 'P' to exit the app", 700, 1100);  // Instructions at the bottom of the screen
	string outText = "Hunger level: " + ofToString(animal.hunger) + ", Thirst Level: " + ofToString(animal.thirst) + ", Happiness Level: " + ofToString(animal.happiness);
	instructions.drawString(outText, 10, 20);  // Happiness, Hunger, and Thirst Level indicators on the top right of the screen

	// -------------- CREATES FRESH VALUES FOR THE THREE PARAMETERS EVERY 1.5 SECONDS ------------------------------------------
	currTime = ofGetElapsedTimeMillis() - startTime;   // Noting down current time as value returned by function minus startTime
	if (currTime >= 1500) {                            // If 1.5 seconds have passed
		animal.tickAnimal();                           // Run the tickAnimal() function from the Animal class
		startTime = ofGetElapsedTimeMillis();          // Reset startTime
	}

	// ------------- CHECKS VALUES UPDATED AND SWITCHES BETWEEN 7 POSSIBLE STATES ----------------------------------------------
	animal.statusAnimal();
	font.drawString("Meowses is " + animal.messageText, 650, 950);

	// ------------- DISPLAYS IMAGE BASED ON ANIMAL'S STATE --------------------------------------------------------------------
	switch (animal.petState) {
	case 1:
		exhaustedCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 2:
		sadCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 3:
		hungryCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 4:
		thirstyCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 5:
		happyCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 6:
		toBePetCat.draw(500, 80, imgWidth, imgHeight);
		break;
	case 7:
		sleepingCat.draw(500, 80, imgWidth, imgHeight);
		break;
	default:
		sleepingCat.draw(500, 80, imgWidth, imgHeight);
		break;

	}

}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){

	switch (key) {

	case 'q':
		animal.feedAnimal();
		animal.clipValues();
		break;

	case 'e':
		animal.quenchAnimal();
		animal.clipValues();
		break;

	case 't':
		animal.petAnimal();
		animal.clipValues();
		break;

	case 'p':
		OF_EXIT_APP(0);

	default:
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
