#include <boost/operators.hpp>
#include <iostream>
#include <vector>
// some silly output iterator examples
struct MyIntOutIter
:std::iterator<std::output_iterator_tag,int> {
	void operator++()const{}
	MyIntOutIter const &operator*()const{
		return *this;
	}
	void operator=(int val) const {
		std::cout << "val= "<<val<<'\n';
	}
};
struct MyIntOutIterBoost
:boost::output_iterator_helper<MyIntOutIterBoost>{
	// obtain an operator* that returns just *this
	// provide assignment operator instead
	void operator=(int val) const{
		std::cout << "value= "<< val<<'\n';
	}
};
struct SummingIter
:std::iterator<std::output_iterator_tag,int>{
	void operator++(){ ++counter; }
	SummingIter& operator*(){
		return *this;
	}
	void operator=(int val) {
		sum+=val;
	}
	double average() const {
		return sum/counter;
	}
	double sum{};
private:
	size_t counter{};
};

int main(){
	std::vector<int> v{3,1,4,1,6,9,2};
	copy(v.begin(),v.end(),MyIntOutIter{});
	copy(v.begin(),v.end(),MyIntOutIterBoost{});
	auto res=copy(v.begin(),v.end(),SummingIter{});
	std::cout << res.sum << " average: "<<res.average();

}
