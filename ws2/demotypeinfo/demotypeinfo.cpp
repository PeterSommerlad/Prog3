#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <string>

// no need to understand that now. Gnu compiler specific
template <typename T>
void showTypeInfoAndValue(T&& x){
	char *toBeFreed = abi::__cxa_demangle(typeid(T).name(),0,0,0);
	std::string result{toBeFreed};
	::free(toBeFreed);
	std::cout << x << " is of type "<<result<<'\n';
}
template <typename ...ALL>
void showTypeInfo(ALL&&... ){}
template <typename T, typename ...ALL>
void showTypeInfo(T &&x,ALL&&...  rest){
	showTypeInfoAndValue(x);
	showTypeInfo(rest...);
}
int main(){
	showTypeInfo(
			'a', '\n', '\x0a',
			1, 42L, 5LL,
			1u, 42ul, 5ull,
			020, 0x1f, 0XFULL,
			/*0f is a syntax error */0.f, .33, 1e9,
			42.E-12L, .3l,
			"hello", "\012\n\\",
			R"(\root.hsr\skripte\)");
std::cout << "------\n";
	showTypeInfoAndValue('a');
	showTypeInfoAndValue(42L);
	showTypeInfoAndValue(0xFULL);
	showTypeInfoAndValue(R"(\root.hsr\skripte\)");
	showTypeInfoAndValue(1/0.0);
	showTypeInfoAndValue(0.0l/0.0l);
}
