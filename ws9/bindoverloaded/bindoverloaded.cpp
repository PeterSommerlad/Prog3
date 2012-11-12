#include <functional>
#include <iostream>


int    f(int i)    { return i; }
double f(double d) { return d*2; }


int main(){
	using std::placeholders::_1;
	using std::bind;
/*
	auto fails=bind(f,bind(f,_1));
*/
	auto foo=bind(static_cast<double(*)(double)>(&f),
			      bind(static_cast<int(*)(int)>(&f),_1));
	std::cout << foo(21);
}

