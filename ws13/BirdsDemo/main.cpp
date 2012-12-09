#include "AnimalBirdHummingbird.h"
// bad code for demonstration purpose only!
int main(){
  cout << "(a)----------------------------\n";
        Hummingbird hummingbird;
        Bird        bird = hummingbird; // slicing
        Animal &    animal = hummingbird;
  cout << "(b)-----------------------------\n";
	    hummingbird.makeSound();
	    bird.makeSound();
	    animal.makeSound(); // non-virtual!
  cout << "(c)-----------------------------\n";
        hummingbird.move();
        bird.move();
        animal.move();
  cout << "(d)-----------------------------\n";
}
