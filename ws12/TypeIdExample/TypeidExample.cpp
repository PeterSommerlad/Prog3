#include <iostream>
#include <string>
#include <memory>
#include <cxxabi.h> // __cxa_demangle

void foo(){}
struct bar{
	void operator()(){}
};

void match(bool b){
	std::cout << (b?"":"no ") << "match"<<std::endl;
}

std::string demangle(char const *name){
	std::unique_ptr<char,void(*)(void *)> toBeFreed( __cxxabiv1::__cxa_demangle(name,0,0,0),::free);
	std::string result(toBeFreed.get());
	return result;
}

int main(){
	using namespace std;
	cout << demangle(typeid(&foo).name()) << endl;
	cout << demangle(typeid(bar()).name()) << endl;
	cout << demangle(typeid((bar())).name()) << endl;
	match (typeid(foo) == typeid(void()));
	match(typeid(foo) == typeid(bar{}()));
}
