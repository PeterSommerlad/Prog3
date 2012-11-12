#include <functional>
#include <iostream>
struct X {
	void foo() const { std::cout << a << " foo\n"; }
	void bar() const { std::cout << b << " bar\n"; }
	int a;
	int b;
};

void bindandmembers(){
	using namespace std::placeholders;
	auto f=std::bind(&X::bar,_1);
	auto g=std::function<void(X const&)>{&X::foo};
	X x{42,43};
	f(x);
	g(x);
}
