#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <cstdlib>
template <typename T> void print(std::vector<T> v);

void demo_erase(){
    std::vector<int> v{1,2,3,4,5};
    print(v);
    v.pop_back(); //{1,2,3,4}
    print(v);
    v.erase(v.begin()); //{2,3,4}
    print(v);
    v.erase(v.begin()+1,v.end()); // {2}
    print(v);
    v.clear();//{}
    print(v);
}

void demo_remove(){
    std::vector<int> v{1,2,3,4,5};
    auto it=remove(v.begin(),v.end(),3); //{1,2,4,5,?}
    print(v);
    print(std::vector<int>{v.begin(),it});
    v.erase(it,v.end()); //{1,2,4,5}
    v.erase(remove(v.begin(),v.end(),2),v.end());//{1,4,5}
    print(v);
}

int main(){
    demo_erase();
    demo_remove();
}

template <typename T> void print(std::vector<T> v){
    copy(v.begin(),v.end(),std::ostream_iterator<T>(std::cout,","));
    std::cout<<" done\n";
}
