

#include<iostream>
#include<string>
// Code formatted for exam, don't mimmick!
// must fit on page widt and height
using std::cout;
using std::string;

struct Animal {
virtual void move() { cout << "---\n";}
Animal(string name):name{name} { cout << "animal " << name <<" born\n";}
virtual ~Animal() { cout << "animal " << name<<" died\n";}
string name;
};

struct Flying : Animal {
void move() { cout << "fly\n";}
Flying(string name):Animal{name} { cout << "flyer hatched\n";}
~Flying() { cout << "bird crashed\n";}
};

struct Swimming : Animal {
void move() { cout << "swim\n";}
Swimming(string name):Animal{name} { cout << "swimmer dives\n";}
~Swimming() { cout << "swimer sank\n";}
};

struct Duck :  Flying, Swimming {
void move() { cout << "ducks fly and swim\n";}
Duck():Flying{"Donald"},Swimming{"Duck"}
{ cout << "duck hatched\n";}
~Duck() { cout << "duck died\n";}
};

int main(){
	Duck donald{};
	donald.move();
}
