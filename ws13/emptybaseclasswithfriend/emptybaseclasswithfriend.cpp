#include "addable.h"
#include <iostream>

class Int
: addable<Int> {
	int i;
public:
	Int & operator+=(Int const &r){
		i += r.i;
		return *this;
	}
	Int(int j):i{j}{}
	int value() const { return i; }
};

int main(){
	Int x{5};
	Int y{37};
	auto z=x+y;
	std::cout << z.value() << '\n';
}
