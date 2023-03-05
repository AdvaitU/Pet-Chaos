#pragma once

#include "animal.h"
using namespace std;

/* -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Particle Class by Dan Buzzo - modified for use 
 YouTube video for usage: https://www.youtube.com/watch?v=XghI0B4EhQI 
 GitHub repo for original code: https://github.com/danbz/art-and-code
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

class particle {
public:

	ofColor color;   // Holds the colour of the particles
	float size;      // Holds the size of each particle
	glm::vec2 force, position, direction;  // Holds x,y co-ordinates

	void update(float input1, float input2);    // Used in ofApp::update()
	void draw(int r, int g, int b);             // Used in ofApp::draw()

	particle(int x, int y, int hue);            // Constructor initialised with x and y co-ordinates and colour
	~particle();                                // Empty destructor

};

/* ofApp Class -------------------------------------------------------------------------------------------------------------------------------------------------------------



--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

class ofApp : public ofBaseApp{

	public:

		// IN-BUILT MEMBERS -----------------------------------------------------------------------------------------------------------------------------------------------

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

		// CUSTOM MEMBERS -------------------------------------------------------------------------------------------------------------------------------------------------

		bool startGame = true;      // Bool to hold whether game has started

		// ANIMAL CLASS OBJECTS -----------------------------------------------------------------------------

		Animal red;      
		Animal blue;
		Animal green;

		// VECTORS CONTAINING PARTICLES ----------------------------------------------------------------------

		vector <particle> redParticles;
		vector <particle> greenParticles;
		vector <particle> blueParticles;

		// TIMER VARIABLES ----------------------------------------------------------------------------------

		int startTime;
		int currTime;
		
		// BACKGROUND IMAGE ---------------------------------------------------------------------------------

		ofImage bg;
		ofImage ss;

		// MOVE PET FUNCTION --------------------------------------------------------------------------------

		void movePet();   // Moves the pet around if infection > 15 AND sets correct image for all stages

};
