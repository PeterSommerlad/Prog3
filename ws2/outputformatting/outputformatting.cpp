#include <iostream>
#include <iomanip>
#include <cmath>






int main(){
    std::cout << 42 << '\n'
              << std::oct << 42 << '\n'
              << std::hex << 42 << '\n';
	std::cout << 42 << '\n'
	          << std::dec << 42 << '\n';
	std::cout << std::setw(10) << 42
	          << std::left<< std::setw(5)<< 43 << "*\n";


	std::cout << std::setw(10) << "hallo"<<"*\n";








// start at line 30
double const pi{std::acos(0.5)*3};
std::cout << std::setprecision(4) << pi << std::endl;
std::cout << std::scientific << pi << std::endl;
std::cout << std::fixed << pi*1e6 << std::endl;

}


// exercise output hex numbers bytes, shorts, etc.
// octal dump program od, hex dump xd
