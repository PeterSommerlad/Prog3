#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <cstdlib>
size_t count_blanks(std::string s){
	size_t count{0};
	for (size_t i=0; i < s.size(); ++i)
		if (s[i] == ' ') ++count;
	return count;
}

void copydemo(std::vector<int> v) {
	using out= std::ostream_iterator<int>;
	copy(v.begin(), v.end(),out{ std::cout,", " });
	v.push_back(42);
	copy(v.begin(), v.begin() + 2, back_inserter(v));
	std::cout <<'\n';
	copy(v.begin(), v.end(),out{ std::cout,", " });
}

void print(int x){
	std::cout << "print:"<< x++ << '\n';
}

void for_each_demo(){
	std::vector<int> v{5,4,3,2,1};
	std::cout << std::accumulate(v.begin(),v.end(),0)<< " = sum\n";

	for_each(v.begin(),v.end(),[](int x){
		std::cout << x++ << '\n';});
	for_each(v.rbegin(),v.rend(),print);

	copydemo(v);
}

void generate_find_demo(){
	std::vector<int> v{};
	srand(time(0));
	generate_n(back_inserter(v),100,[]{return rand()%100;});
	auto zero_it=find(v.begin(),v.end(),0);
	if (zero_it == v.end()){
		std::cout << "\nno zero found \n";
	} else {
		std::cout << "\nfound zero at position:"
				<< distance(v.begin(),zero_it)<<'\n';
	}
	auto odd=find_if(v.begin(),v.end(),[](int x){return x%2;});
	if (odd == v.end()){
		std::cout << "no odd number found\n";
	} else {
		std::cout << "found odd number:" << *odd
				<< "\nat position:"<<distance(v.begin(),odd)<< '\n';
	}
	std::cout << count(v.begin(),v.end(),42)<<" times 42\n";
	std::cout << count_if(v.begin(),v.end(),
			[](int x){return 0==(x%2);})<<" even numbers\n";
}

int main(){
	std::string s{"A journey of a thousand miles begins with a single step"};
	std::cout << count(s.begin(),s.end(),' ') << " blanks\n";
	std::cout << "distance: "<< distance(s.begin(),s.end()) <<'\n';
	std::cout << "in a string of length: "<< s.size()<<'\n';
	std::cout << count_blanks(s) << " blanks\n";

	for_each_demo();
	generate_find_demo();
}

