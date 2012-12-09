#include "abstractinterface.h"
#include <iostream>
void doit(abstractinterface const &ai){
	std::cout << ai.func(42) << '\n';
}



