#include <iostream>
#include <type_traits>
#include <string>
#include <vector>

template <typename T>
void foo(T &&universal){
	if (std::is_lvalue_reference<decltype(universal)>::value)
		std::cout << "lvalue reference\n";
	else if (std::is_rvalue_reference<decltype(universal)>::value)
		std::cout << "rvalue reference\n";
	else
		std::cout << "value\n"; // never happens
}

template <typename T, typename ...ARGS>
T make(ARGS && ... args){
	return T(args...);
}

int main(){
	foo(1); // rvalue ref
	int i{};
	foo(i); // lvalue ref
	foo(std::move(i)); // rvalue ref
	int &j=i;
	foo(j); // lvalue ref
	int const &g=5;
	foo(g); // lvalue ref
	foo(std::move(g)); // rvalue ref
	int &&h=6*7;
	foo(h); // lvalue ref
	auto &&k=i; // universal reference  k
	foo(k); // lvalue ref
	auto x=make<std::string>(5,'a');
	std::cout << "x = "<< x << ".\n";
	auto y=make<std::vector<int>>(5,6);
	std::cout << "y.size():"<<y.size()<<'\n';
}



