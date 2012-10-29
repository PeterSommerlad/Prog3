#include <vector>
#include <iostream>
int main(){
	std::vector<int> v{3,1,4,1,5,9,2,6};
	for(auto it=v.cbegin(); it != v.cend() ; ++it){
		std::cout << *it << " is "
				  << ((*it%2)?"odd":"even") <<'\n';
	}
	for (std::vector<int>::const_reverse_iterator
			rit=v.crbegin(); rit != v.crend(); ++rit){
		std::cout << *rit << ", ";
	}
}

