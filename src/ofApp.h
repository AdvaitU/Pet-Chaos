#pragma once

#include "animal.h"
//#include "animal.cpp"
using namespace std;


class particle {
public:
	// our new particle class
	// with each object containing an x and y position, and a vector direction as vx and vy and a size
	ofColor color;
	float size;
	glm::vec2 force, position, direction;


	// we also define two methods that the particle object understands
	void update();
	void draw();

	// and define a particle contructor and a destructor (the destructor is denoted by the tilde (~) character prefix
	// the contructor is expecting to be passed an initial x and y co-ordinate for the new particle
	particle(int x, int y, int hue);
	~particle();
};


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

		void makeParticle(int i1, int i2);

		Animal red;      // Instantiating three objects from the Animal class
		Animal blue;
		Animal green;

		vector <particle> particles;
		int hue;

		int para1 = 20;
		int para2 = 200;



};
