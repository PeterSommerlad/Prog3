#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
int main(){
    using in=std::istream_iterator<int>;
    std::vector<int> v{in{std::cin},in{}};
    auto const even=[](int x){ return 0 == x % 2; };
    auto toremove=remove_if(v.begin(),v.end(),even);
    using out=std::ostream_iterator<int>;
    copy(v.begin(),v.end(),out{std::cout,", "});
    std::cout << '\n';
    v.erase(toremove,v.end());
    copy(v.begin(),v.end(),out{std::cout,", "});
    std::cout << '\n';
    v.erase(remove(v.begin(),v.end(),0),v.end());
}

