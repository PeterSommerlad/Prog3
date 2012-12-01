#include <typeinfo>
#include <iostream>
#include <string>
#include <memory>
#include <cxxabi.h> // __cxa_demangle

void myfree(void * ptr){
	std::cout << "freeing\n";
	::free(ptr);
}

std::string demangle(char const *name){
	std::unique_ptr<char,decltype(&::free)>
	   toBeFreed{ __cxxabiv1::__cxa_demangle(name,0,0,0),&::free};
	std::string result(toBeFreed.get());
	return result;
}

template <typename T>
void printIdRef(T const & t) {
	std::cout << "printIdRef(T const &t): " << demangle(typeid(t).name()) << std::endl;
}
template <typename T>
void printIdVal(T t) {
	std::cout << "printIdVal(T t): " << demangle(typeid(t).name()) << std::endl;
}

struct Double { double d;};

int main(){
	printIdRef("hello");
	printIdVal("hello");
	printIdRef(Double());
	printIdVal(Double());
}
