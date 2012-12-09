#ifndef ANIMALBIRDHUMMINGBIRD_H_
#define ANIMALBIRDHUMMINGBIRD_H_
#include<iostream>
// Code formatted for exam, don't mimmick!
// must fit on page widt and height
using std::cout;

struct Animal {
void makeSound() { cout << "---\n";}
virtual void move() { cout << "---\n";}
Animal() { cout << "animal born\n";}
~Animal() { cout << "animal died\n";}
};

struct Bird : Animal {
virtual void makeSound() { cout << "chirp\n";}
void move() { cout << "fly\n";}
Bird() { cout << "bird hatched\n";}
~Bird() { cout << "bird crashed\n";}
};

struct Hummingbird :  Bird {
void makeSound() { cout << "peep\n";}
virtual void move() { cout << "hum\n";}
Hummingbird() { cout << "hummingbird hatched\n";}
~Hummingbird() { cout << "hummingbird died\n";}
};

#endif /*ANIMALBIRDHUMMINGBIRD_H_*/
