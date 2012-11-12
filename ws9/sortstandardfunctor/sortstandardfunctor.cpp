#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>




void print(std::vector<int> v, std::ostream& out){
	std::ostream_iterator<int> os{out,", "};
	copy(v.begin(),v.end(),os);
	out << '\n';
}


void demosort(){
	std::vector<int> v{-1,2,-5,3,-4,-2};
	print(v,std::cout);
	sort(v.begin(),v.end(),std::greater<int>{});
	print(v,std::cout);
}




int main(){
	demosort();
}












