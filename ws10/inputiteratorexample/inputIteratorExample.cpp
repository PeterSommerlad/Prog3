#include "IntInputter.h"
#include "IntInputterPtr.h"
#include "IntInputterPtrBoost.h"

#include <vector>
#include <iostream>
#include <sstream>

void exampleInputIterator(){
	IntInputter eof{};
	std::istringstream input{"3 1 4 1 5 9 2"};
	IntInputter in{input};
	std::vector<int> v{in,eof};
	copy(v.begin(),v.end(),
			std::ostream_iterator<int>{std::cout,"\n"});
}
void exWithPtr(){
	IntInputterPtr eof{};
	std::istringstream input{"1 2 3 4 5 6 7"};
	IntInputterPtr in{input};
	std::vector<int> v{in,eof};
	copy(v.begin(),v.end(),
			std::ostream_iterator<int>{std::cout,"\n"});
}

void exWithPtrAndBoost(){
	IntInputterPtrBoost eof{};
	std::istringstream input{"42 42 44 29 28 11"};
	IntInputterPtrBoost in{input};
	std::vector<int> v{in,eof};
	copy(v.begin(),v.end(),
			std::ostream_iterator<int>{std::cout,"\n"});
}

int main(){
	exampleInputIterator();
	exWithPtr();
	exWithPtrAndBoost();

}



