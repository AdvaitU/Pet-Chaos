#pragma once

#include "ofMain.h"
using namespace std;

// Animal Class with one instance being used in the final code

class Animal {
public:

	float hunger;        // Hunger level of the animal
	float thirst;        // Thirst level of the animal
	float happiness;     // Happiness level of the animal
	bool happinessTick = true;   // Bool to judge either happiness decreasing every tick or not
	string name;                 // For naming the cat if required
	int petState;        // Switches between 7 possible states that decide the output image and text string
	string messageText;  // Output text string - 7 possibilities

	Animal();            // Empty constructor and destructor
	~Animal();

	void set(float i1 = 5.0, float i2 = 5.0, float i3 = 5.0);  // For setting values of hunger, thirst, and happiness - in that order - as floats
	
	void feedAnimal();      // Reduces hunger level, increase happiness
	void petAnimal();       // Increases happiness
	void quenchAnimal();    // Reduces thirst level, increases happiness (possibly)
	void tickAnimal();      // Emulating the passing of time - animal gets varying degrees of thirstier, hungrier and less happy with no attention
	void statusAnimal();    // Switch case to set petState in class

	void clipValues();      // Clips the hunger, happiness and thirst values to between 0 and 10


};
