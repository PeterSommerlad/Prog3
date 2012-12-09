#include "abstractinterface.h"

struct concrete:abstractinterface{
	int func(int i) const {
		return i*i;
	}
};

struct otherconcrete:abstractinterface{
	int func(int i) const {
		return i/2;
	}
};

struct unrelated {
	int func(int j)const {
		return 2 * j;
	}
};

#include <iostream>
template <typename T>
void justdoit(T const &t){
	std::cout << t.func(42) << '\n';
}


int main(){
	concrete c;
	doit(c);
	otherconcrete oc;
	doit(oc);

	justdoit(c);
	justdoit(oc);
	justdoit(unrelated{});
}



