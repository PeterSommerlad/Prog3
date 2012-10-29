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
	std::rotate(v.begin(),v.begin()+3,v.end());
	show(v, cout);
	std::reverse(v.begin(),v.end());
	show(v, cout);
}
