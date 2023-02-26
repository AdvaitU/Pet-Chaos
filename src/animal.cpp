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
	chaos = i2;
	infection = i3;

}

void Animal::feedAnimal()
{

	hunger -= ofRandom(0.5, 1.5);
	chaos += ofRandom(0.1, 0.5);

}

void Animal::petAnimal()
{

	chaos += ofRandom(0.5, 1.5);

}

void Animal::quenchAnimal()
{
	infection -= ofRandom(0.5, 1.5);
	chaos += ofRandom(0.1, 0.5);

}

void Animal::tickAnimal()
{

	hunger += ofRandom(0.4, 0.1);
	infection += ofRandom(0.4, 0.1);
	chaos -= ofRandom(0.0, 1.0);

	clipValues();  // Clip values between relevant range
}

void Animal::clipValues()
{

	if (hunger >= 10.0) {
		hunger = 10.0;
	}
	if (hunger < 0.0) {
		hunger = 0.0;
	}

	if (infection >= 255) {
		infection = 255;
	}
	if (infection <= 0) {
		infection = 0;
	}

	if (chaos >= 10.0) {
		chaos = 10.0;
	}
	if (chaos <= 0.0) {
		chaos = 0.0;
	}

}
