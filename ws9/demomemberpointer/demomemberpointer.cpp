#include <iostream>


struct X {
	void foo() const { std::cout << a << " foo\n"; }
	void bar() const { std::cout << b << " bar\n"; }
	int a;
	int b;
};

void doit(void (X::*mfunc)() const, X const &x){
	(x.*mfunc)(); // parenthesis needed
}

void change(int X::*memvar, X& x, int val){
	x.*memvar = val;
}


int main(){
	X x{1,2};
	doit(&X::foo,x);
	doit(&X::bar,x);
	change(&X::a,x,42);
	change(&X::b,x,43);
	doit(&X::foo,x);
	doit(&X::bar,x);
}
