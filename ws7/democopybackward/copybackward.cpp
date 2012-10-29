#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
void show(std::vector<int> const &v, std::ostream& os) {
	std::ostream_iterator<int> out(os,", ");
	copy(v.begin(), v.end(), out);
	os << '\n';
}
int main(){
	std::vector<int> v{3,1,4,1,5,9,2,6};
	using std::cout;
	show(v, cout);
	std::copy(v.begin()+2,v.end(),v.begin());
	show(v, cout);
	std::copy_backward(v.begin(),v.end()-2,v.end());
	show(v,cout);
	auto middle=v.begin()+(v.size()/2);
	std::swap_ranges(v.begin(),middle,middle);
	show(v,cout);
}
