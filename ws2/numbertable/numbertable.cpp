#include<iostream>
#include<iomanip>
#include <locale>
int main(){
    for (unsigned n=0;n!=256;++n){
        std::cout << std::setfill(' ') <<std::setw(4)
                  << std::dec << n
                  << std::showbase << std::setw(6)
                  << std::oct<< n
                  << std::noshowbase << "  0x"
                  << std::setfill('0') << std::setw(2)
                  << std::hex << n << std::endl;
    }
}
