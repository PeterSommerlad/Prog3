#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

int main(){
	using std::cout;
	using std::placeholders::_1;
	std::ostream_iterator<int> out{cout,", "};
	std::vector<int> numbers(10);
	iota(numbers.begin(),numbers.end(),1);
	copy(numbers.begin(),numbers.end(),out); cout <<'\n';
	transform(numbers.begin(),numbers.end(),out,
	  bind(std::plus<int>{},_1,10)); cout <<'\n';
	transform(numbers.begin(),numbers.end(),out,
	  bind(std::multiplies<int>(),_1,_1)); cout <<'\n';
}
