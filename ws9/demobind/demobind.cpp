#include <functional>
#include <iostream>

int main(){
	using std::placeholders::_1;
	auto odd=std::bind(std::modulus<int>{},_1,2);
	using std::cout;
	cout << "odd(42) =" << odd(42)<<'\n';
	auto oddl=[](int x){ return std::modulus<int>{}(x,2);};
	cout << "oddl(42) =" << oddl(42)<<'\n';
	void bind_expressions();
	bind_expressions();
	void bindandmembers();
	bindandmembers();
}
