#include "animal.h"
using namespace std;


Animal::Animal()
{

}

Animal::~Animal()
{
	
}

void Animal::set(float i1, float i2, float i3)
{

	hunger = i1;
	thirst = i2;
	happiness = i3;

}

void Animal::feedAnimal()
{

	hunger -= ofRandom(0.5, 1.5);
	happiness += ofRandom(0.1, 0.5);

}

void Animal::petAnimal()
{

	happiness += ofRandom(0.5, 1.5);

}

void Animal::quenchAnimal()
{
	thirst -= ofRandom(0.5, 1.5);
	happiness += ofRandom(0.1, 0.5);

}

void Animal::tickAnimal()
{

	hunger += ofRandom(0.4, 0.1);
	thirst += ofRandom(0.4, 0.1);

	if (happinessTick == true) {
		happiness -= ofRandom(0.0, 1.0);
	}

	happinessTick != happinessTick;   // Set happinessTick as reverse so it runs on alternate runs of tickAnimal()

	clipValues();  // Clip values between 0 and 10
}

void Animal::statusAnimal()
{

	if ((hunger >= 7.0) && (thirst >= 7.0) && (happiness >= 6.0)) {   // V hungry and thirsty but happy
		petState = 1;     // exhaustedCat
		messageText = "hungry and parched.";
	} 
	else if ((hunger >= 7.0) && (thirst >= 7.0) && (happiness <= 6.0)) {     // V. hungry and thirsty and unhappy
		petState = 2;    // sadCat
		messageText = "hungry, thirsty and deeply dissatisfied.";
	}
	else if ((hunger >= 7.0) && (thirst < 7.0)) {                  // Hungry but not thirsty - Happiness independent
		petState = 3;    // hungryCat
		messageText = "hungry!";
	}
	else if ((hunger < 7.0) && (thirst >= 7.0)) {                 // Thirsty but not hungry - Happiness Independent
		petState = 4;    // thirstyCat
		messageText = "parched!";
	}
	else if ((hunger < 7.0) && (thirst < 7.0) && (happiness > 6.0)) {  // Not hungry, not thirsty - Just happy
		petState = 5;   // happyCat
		messageText = "extremely happy. He's glowing!";
	}
	else if ((hunger < 7.0) && (thirst < 7.0) && (happiness <= 4.0)) {  // Not hungry, not thirsty but unhappy
		petState = 6;   // toBePetCat
		messageText = "healthy but could use a few pets.";
	}
	else {   // Or else
		petState = 7;   // sleepingCat
		messageText = "asleep. He seems well.";
	}
}

void Animal::clipValues()
{

	if (hunger >= 10.0) {
		hunger = 10.0;
	}
	if (hunger < 0.0) {
		hunger = 0.0;
	}

	if (happiness >= 10.0) {
		happiness = 10.0;
	}
	if (happiness <= 0.0) {
		happiness = 0.0;
	}

	if (thirst >= 10.0) {
		thirst = 10.0;
	}
	if (thirst <= 0.0) {
		thirst = 0.0;
	}

}
