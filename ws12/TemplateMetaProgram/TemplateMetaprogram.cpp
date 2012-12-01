#include <iostream>

template <int X, unsigned int N>
struct Hoch {
	static const int result = X * Hoch<X,N-1>::result ;
};

template<int X>
struct Hoch<X,0> {
	static const int result = 1;
};

const int v=Hoch<3,3>::result;
int a[Hoch<2,10>::result]; // proof that result is compile time constant

int main(){
	using namespace std;
	cout << "sizeof a:" << sizeof(a)<<endl;
	cout << "Hoch<5,4> = " << Hoch<5,4>::result<<endl;
	cout << "Hoch<5,3> = " << Hoch<5,3>::result<<endl;
	cout << "Hoch<5,2> = " << Hoch<5,2>::result<<endl;
	cout << "Hoch<5,1> = " << Hoch<5,1>::result<<endl;
	cout << "v = " << v << endl;
}
