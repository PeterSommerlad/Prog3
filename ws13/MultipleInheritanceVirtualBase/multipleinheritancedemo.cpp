

#include<iostream>
#include<string>
using std::cout;
using std::string;

struct Animal {
virtual void move() { cout << "---\n";}
Animal(string name="anonymous"):name{name} { cout << "animal " << name <<" born\n";}
virtual ~Animal() { cout << "animal " << name<<" died\n";}
string name;
};

struct Flying : virtual Animal {
void move() { cout << "fly\n";}
Flying(string name="flyer"):Animal{name} { cout << "flyer hatched\n";}
~Flying() { cout << "bird crashed\n";}
};

struct Swimming : virtual Animal {
void move() { cout << "swim\n";}
Swimming(string name):Animal{name} { cout << "swimmer " << this->name << " dives\n";}
~Swimming() { cout << "swimer sank\n";}
};

struct Duck :  Flying, Swimming {
void move() { cout << "ducks fly and swim\n";}
Duck():Animal{"Donald"},Swimming(string{"Duck"})
{ cout << "duck hatched\n";}
~Duck() { cout << "duck died\n";}
};

int main(){
	Duck donald{};
	donald.move();
}
