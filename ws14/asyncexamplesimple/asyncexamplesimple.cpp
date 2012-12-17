#include <future>
#include <iostream>
#include <cmath>

double do_some_expensive_calculation(double input){
	return std::sqrt(input); // simulate that
}

int main(){
	auto result=std::async(std::launch::deferred,
                         do_some_expensive_calculation,81.0);
	std::cout << "do some other useful things\n" ;
	std::cout << "waiting for he result...\n";
	std::cout << "the result is= "<< result.get()<<'\n';
}
