#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
int main(){
    using in=std::istream_iterator<std::string>;
    std::vector<std::string> v{in{std::cin},in{}};
    auto s=accumulate(v.begin(),v.end(),std::string{});
    std::cout << s;
}
