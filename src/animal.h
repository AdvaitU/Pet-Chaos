#pragma once

#include "ofMain.h"
using namespace std;

// Animal Class with three instances being used in the final code ----------------------------------------------------------------------------------------------------------

class Animal {
public:

	// MAIN VARIABLE COUNTERS ----------------------------------------------------

	float hunger;        // Affects how quickly the diarrhoea spreads
	float chaos;         // Affects how big the particles are
	int infection;       // Affects the position of the cat

	bool h = false;      // Is hunger > 10?
	bool c = false;      // Is chaos > 10?
	bool i = false;      // Is infection > 15?

	int initX;           // X and Y positions of where particle and cat are drawn
	int initY;

	// IMAGES ---------------------------------------------------------------------

	ofImage happy;       // Images for all 3 cat states
	ofImage neutral;
	ofImage sad;

	// FUNCTIONS ------------------------------------------------------------------

	Animal();            // Empty constructor and destructor
	~Animal();

	// CUSTOM SETUP FUNCTIONS -----------------------------------------------------

	void set(float i1 = 5.0, float i2 = 5.0, float i3 = 5.0, int x = 100, int y = 100);  // For setting values of hunger, thirst, and happiness - in that order - as floats
	void loadImage(string h, string n, string s);    // Loads up all images at once, takes 3 string filenames as arguments
	
	// RUNNING LOOP FUNCTIONS -----------------------------------------------------
	// Names don't represent the function in the programme - the game was initially supposed to be something way more occulty hahahaha - Didn't change the names because I didn't want to break anything
	
	void offerBlood();      // Reduces hunger level, increase happiness
	void usePotion();       // Increases happiness
	void sacrificeAnimal(); // Reduces thirst level, increases happiness (possibly)
	void tickAnimal();      // Emulating the passing of time - animal gets varying degrees of thirstier, hungrier and less happy with no attention
	void statusAnimal();

	// UTILITY FUNCTIONS ----------------------------------------------------------

	void clipValues();      // Clips the hunger and chaos values to between (-5) and 15, and infection between 0 and 50

};
