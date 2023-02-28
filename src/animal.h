#pragma once

#include "ofMain.h"
using namespace std;

// Animal Class with one instance being used in the final code

class Animal {
public:

	float hunger;        
	float chaos;
	int infection;        // Affects how much the colour spreads into the background

	bool h = false;
	bool c = false;
	bool i = false;

	int initX;
	int initY;

	ofImage happy;
	ofImage neutral;
	ofImage sad;

	Animal();            // Empty constructor and destructor
	~Animal();

	void set(float i1 = 5.0, float i2 = 5.0, float i3 = 5.0, int x = 100, int y = 100);  // For setting values of hunger, thirst, and happiness - in that order - as floats
	void loadImage(string h, string n, string s);
	
	void offerBlood();      // Reduces hunger level, increase happiness
	void usePotion();       // Increases happiness
	void sacrificeAnimal();    // Reduces thirst level, increases happiness (possibly)
	void tickAnimal();      // Emulating the passing of time - animal gets varying degrees of thirstier, hungrier and less happy with no attention
	void statusAnimal();

	void clipValues();      // Clips the hunger, happiness and thirst values to between 0 and 10


};
