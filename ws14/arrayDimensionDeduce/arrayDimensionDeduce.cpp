#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T, unsigned N>
void printArray(std::ostream &out, T const (&x)[N]){
	copy(x, x+N, std::ostream_iterator<T>{out,", "});
	out << '\n';
}

int main(){
	int a[]={1,2,3};
	printArray(std::cout,a);

	char s[6]{"hello"};
	printArray(std::cout,s);

	int five[5]{};
	int four[4]={1,2,3,4};
	printArray(std::cout,five);
	double d[4]{1.0, 2.0,};
	printArray(std::cout,d);
	double m[2][3]{{1,2,3},{4,5,6}};
	printArray(std::cout,m[0]);
	char str[]="world";
	printArray(std::cout,str);

}
