#include "animal.h"
using namespace std;

Animal::Animal()
{
	// Empty Constructor
}

Animal::~Animal()
{
	// Empty Destructor
}
// SETUP FUNCTIONS -------------------------------------------------------------------------------------------------------------------------------------------------------
// 
// Sets initial values of hunger, chaos, infection, and x and y co-ordinates for position. Used almost as a constructor in code ------------------------------------------

void Animal::set(float i1, float i2, float i3, int x, int y)
{

	hunger = i1;
	chaos = i2;
	infection = i3;
	initX = x;
	initY = y;

}

// Loads all images for happy, neutral (spooked) and sad (distressed) cat ------------------------------------------------------------------------------------------------

void Animal::loadImage(string h, string n, string s)
{

	happy.load(h);
	neutral.load(n);
	sad.load(s);

	//happy.setImageType(OF_IMAGE_COLOR_ALPHA);    // Experiment with JPG with white background as COLOUR_ALPHA
	//neutral.setImageType(OF_IMAGE_COLOR_ALPHA);
	//sad.setImageType(OF_IMAGE_COLOR_ALPHA);

}

// RUNNING LOOP FUNCTIONS ------------------------------------------------------------------------------------------------------------------------------------------------
// 
// The following functions run when relevant button is pressed and decrease hunger, chaos, and infection levels of the object --------------------------------------------

void Animal::offerBlood()
{

	hunger -= ofRandom(0.5, 1.5);
	chaos -= ofRandom(0.1, 0.5);
	clipValues();

}

void Animal::usePotion()
{

	chaos -= ofRandom(3.0, 7.0);
	clipValues();

}

void Animal::sacrificeAnimal()
{

	infection -= ofRandom(0.5, 1.5);
	chaos -= ofRandom(0.1, 0.5);
	clipValues();

}

// Function to periodically increase calues when the programme 'ticks' ---------------------------------------------------------------------------------------------------

void Animal::tickAnimal()
{

	hunger += ofRandom(1.0, 1.3);
	infection += ofRandom(1, 5);
	chaos += ofRandom(0.0, 1.0);

	clipValues();  // Clip values between relevant range
}

// Function sets booleans to true or false based on range that h, c, and i values are found in ---------------------------------------------------------------------------

void Animal::statusAnimal()
{

	if (hunger >= 10) {
		h = true;
	}
	else h = false;

	if (hunger <= -1) {
		hunger = 10;
	}

	if (chaos >= 10) {
		c = true;
	}
	else c = false;

	if (chaos <= -1) {
		chaos = 10;
	}

	if (infection >= 10) {
		i = true;
	}
	else i = false;
}

// Clip values between indicated ranges, run at the end of tickAnimal() ---------------------------------------------------------------------------------------------------

void Animal::clipValues()
{

	if (hunger >= 15.0) {
		hunger = 15.0;
	}
	if (hunger < -5.0) {
		hunger = -5.0;
	}

	if (infection >= 50) {
		infection = 50;
	}
	if (infection <= 0) {
		infection = 0;
	}

	if (chaos >= 15.0) {
		chaos = 15.0;
	}
	if (chaos <= -5.0) {
		chaos = -5.0;
	}

}
