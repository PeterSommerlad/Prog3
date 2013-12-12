
#include <type_traits>


template <typename U>
typename std::enable_if<std::is_unsigned<U>::value,bool>::type
is_prime(U u){
	return true; // logic omitted
}



int main(){
	is_prime(4u);
	//is_prime(5); // doesn't compile
}
