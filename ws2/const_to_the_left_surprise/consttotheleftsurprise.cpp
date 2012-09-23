#include <iostream>
int main(){
    int i{42};
    const int &rci{i}; //~~ int const &rci{i};
    //rci++; // does not compile
    using refi=int &; // type reference to int
    const refi ri{i}; // const without effect
    ri++; // allowed, reference to int
    std::cout << i; // 43
    void dummy();dummy();
}
void dummy(){
    int i{42};
    const int *pci{&i}; //pointer to const int
    //(*pci)++; // does not compile
    using ptri=int *; // type pointer to int
    const ptri pi{&i}; // const effect on pi only
    (*pi)++; // allowed, const pointer to int
    std::cout << i; // 43


    //int & const ref{i};
}
