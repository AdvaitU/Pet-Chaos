#pragma once

#include "ofMain.h"
using namespace std;

// Animal Class with one instance being used in the final code

class Animal {
public:

	float hunger;        
	float chaos;
	int infection;        // Affects how much the colour spreads into the background

	Animal();            // Empty constructor and destructor
	~Animal();

	void set(float i1 = 5.0, float i2 = 5.0, float i3 = 5.0);  // For setting values of hunger, thirst, and happiness - in that order - as floats
	
	void feedAnimal();      // Reduces hunger level, increase happiness
	void petAnimal();       // Increases happiness
	void quenchAnimal();    // Reduces thirst level, increases happiness (possibly)
	void tickAnimal();      // Emulating the passing of time - animal gets varying degrees of thirstier, hungrier and less happy with no attention

	void clipValues();      // Clips the hunger, happiness and thirst values to between 0 and 10


};
