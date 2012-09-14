#include <iostream>

int main() {
	int anAnswer{42};
	double const g{9.81};
	auto const i=5;
	std::cout << i << std::endl;

	char constexpr a{'a'};
	int constexpr x[i]={1,2,3,4,5};
	std::cout << a << std::endl;

	int const theAnswer{6*7};

}
