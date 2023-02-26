#pragma once

#include "animal.h"
//#include "animal.cpp"
using namespace std;



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofImage hungryCat;          // Objects to hold 7 different images showing cats
		ofImage happyCat;
		ofImage toBePetCat;
		ofImage sadCat;
		ofImage sleepingCat;
		ofImage thirstyCat;
		ofImage exhaustedCat;

		ofTrueTypeFont font;           // Objects holding font styles for instructions and main text output
		ofTrueTypeFont instructions;

		int startTime;                // Variables to contain time in milliseconds as ints to trigger ticks
		int currTime;

		Animal animal;                // Instance of Animal class
		

};
