#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <string>

// no need to understand that now. Gnu compiler specific
template <typename T>
void showTypeInfoAndValue(T x){
	char *toBeFreed = abi::__cxa_demangle(typeid(T).name(),0,0,0);
	std::string result{toBeFreed};
	::free(toBeFreed);
	std::cout << x << " is of type "<<result<<'\n';
}

int main(){
	showTypeInfoAndValue('a');
	showTypeInfoAndValue(42L);
	showTypeInfoAndValue(0xFULL);
	showTypeInfoAndValue(R"(\root.hsr\skripte\)");
	showTypeInfoAndValue(1/0.0);
	showTypeInfoAndValue(0.0l/0.0l);
}
