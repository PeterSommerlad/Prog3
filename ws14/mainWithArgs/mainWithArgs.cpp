#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

int main(int argc, char *argv[]){
	copy(argv+1, argv+argc,
	     std::ostream_iterator<std::string>{std::cout,"-"});
}
