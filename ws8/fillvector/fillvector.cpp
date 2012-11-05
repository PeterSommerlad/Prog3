#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <cstdlib>
#include <sstream>

std::vector<int> fillWhile(std::istream &in){
    std::vector<int> v{};
    int val{};
    while(in >> val)
        v.push_back(val);
    return v;
}



std::vector<int> fillIter(std::istream &in){
    std::vector<int> v{};
    using initer = std::istream_iterator<int>;
    copy(initer{in},initer{},back_inserter(v));
    return v;
}
std::vector<int> fillIter1(std::istream &in){
    using initer = std::istream_iterator<int>;
    return std::vector<int>{initer{in},initer{}};
}
void demoVectorCtor(){
    std::vector<int> tenzeros(10);
    std::vector<int> five_minusones(5,-1);
    std::vector<std::string> fourhellos{4,"hello"};

}




std::vector<std::string> fillWithInsert(){
    std::vector<std::string> v{};
    v.insert(v.end(),2,"back");
    v.insert(v.begin(),3,"front");
    v.insert(v.begin(),"front again");
    v.push_back("back again");
    return v;
}


std::vector<int> fillWithfill(){
    std::vector<int> v(10);
    fill(v.begin(),v.end(),2);
    std::vector<std::string> vs;
    fill_n(std::inserter(vs,vs.end()),3,"hello");
    return v;
}
// should use std::fill to avoid CDT name lookup problem


int accumulateIota(){
    std::vector<int> v(100);
    iota(v.begin(),v.end(),1);
    return accumulate(v.begin(),v.end(),0);
}





void demo_generate(){
    std::vector<int> v(10);
    generate(v.begin(),v.end(),std::rand);
    std::vector<double> w{};
    double x{2.0};
    generate_n(std::back_inserter(w),5,[&x]{return x*=2.0;});
    copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout,"\n"));
    copy(w.begin(),w.end(),std::ostream_iterator<double>(std::cout,"\n  "));


}
int main(){
    std::istringstream is{"1 2 3 4 5"};
    std::vector<int> v = fillIter1(is);
    std::cout << accumulate(v.begin(),v.end(),0) << "\n";

    std::cout << accumulateIota() << "\n";
    auto vs=fillWithInsert();
    using oi=std::ostream_iterator<std::string>;
    copy(vs.begin(),vs.end(),oi{std::cout,","});
    std::cout << "\n";
    demo_generate();
}
