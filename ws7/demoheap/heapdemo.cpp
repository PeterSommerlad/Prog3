#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

void show(std::vector<int> const &v, std::ostream& os) {
	std::ostream_iterator<int> out(os,", ");
	copy(v.begin(), v.end(), out);
	os << std::boolalpha << "is " <<
			(is_heap(v.begin(),v.end())?"a":"no")
			<< " heap.\n";
}

int main(){
	std::vector<int> v{3,1,4,1,5,9,2,6};
	using std::cout;                   show(v, cout);
	std::make_heap(v.begin(),v.end()); show(v, cout);
	std::pop_heap(v.begin(),v.end());  show(v, cout);
	v.pop_back();                      show(v, cout);
	v.push_back(8);	                   show(v,cout);
	std::push_heap(v.begin(),v.end()); show(v,cout);
	std::sort_heap(v.begin(),v.end()); show(v,cout);
}
