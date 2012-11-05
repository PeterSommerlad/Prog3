#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>
int main(){
	std::ostream_iterator<unsigned> out{std::cout,", "};
	std::vector<unsigned> v(10,1);
	copy(v.begin(),v.end(),out); std::cout << '\n';
	partial_sum(v.begin(),v.end(),v.begin());
	copy(v.begin(),v.end(),out); std::cout << '\n';
	transform(v.begin(),v.end(),v.begin(),out,
			std::multiplies<unsigned>{});
}
