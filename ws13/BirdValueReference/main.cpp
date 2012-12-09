#include "AnimalBirdHummingbird.h"

int main(){
  cout << "(a)----------------------------" << endl;
	    Bird        bibo();
        Hummingbird hummingbird;
        Bird        bird = hummingbird;
        Animal &    animal= hummingbird;
  cout << "(b)-----------------------------" << endl;
	    hummingbird.makeSound();
	    bird.makeSound();
	    animal.makeSound();
  cout << "(c)-----------------------------" << endl;
        hummingbird.move();
        bird.move();
        animal.move();
  cout << "(d)-----------------------------" << endl;
}
