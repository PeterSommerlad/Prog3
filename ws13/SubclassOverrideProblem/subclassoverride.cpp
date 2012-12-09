#include <iostream>

struct Base {
	void foo(int i) const {
		std::cout << "foo(i):" << i << '\n';
	}
};

struct Derived:Base {
	void foo() { // hides Base::foo(int)
		std::cout << "Derived::foo()\n";
	}
};


int main(){
	Base b{};
	b.foo(42);
	Derived d{};
	//d.foo(42);// cannot call Base::foo(int)
	d.foo();
}



