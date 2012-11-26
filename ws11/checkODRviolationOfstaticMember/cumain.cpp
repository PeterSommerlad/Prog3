#include "templatewithstaticmember.h"
#include <iostream>

int main(){
	int foo();
	std::cout << staticmember<double>::dummy << '\n';
	std::cout << staticmember<int>::dummy << '\n';
	std::cout << foo() << '\n';
	std::cout << staticmember<int>::dummy << '\n';
}
