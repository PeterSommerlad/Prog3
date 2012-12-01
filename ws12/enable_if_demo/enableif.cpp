
#include <type_traits>


template <typename U>
bool is_prime(U u,
		typename std::enable_if<std::is_unsigned<U>::value>::type* dummy ={}){
	return true; // logic omitted
}



int main(){
	is_prime(4u);
	//is_prime(5); // doesn't compile
}
