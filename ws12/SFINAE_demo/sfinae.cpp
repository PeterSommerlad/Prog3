#include <iostream>
#include <vector>
void foo(char i){
	std::cout << "foo(char):" << i << '\n';
}
template <typename T>
typename T::size_type foo(T const &t){
	std::cout << "foo(T const &): ";
	return typename T::size_type{};
}

int main(){
	foo(42); // foo(int)? -> foo<T=int>() geht nicht -> foo(char)
	foo(std::string{});
	foo('a');
	foo(std::vector<int>{1,2,3,4});
	//foo(std::cout);

}
