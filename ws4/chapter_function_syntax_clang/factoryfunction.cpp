#include <fstream>
#include <iostream>







std::ofstream fileFactory(std::string filename){
	std::ofstream theFile(filename.c_str());
	return theFile;
}






void writeToFile(std::ofstream file){
	file << "hello, world\n";
}





int main(){
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
	std::ofstream out=fileFactory("hello.txt");
	out << "hello\n";
	writeToFile(std::move(out));
	// cannot use out here anymore
	if (out << "more?"){
		std::cout << "oops out should be empty now\n";
	}
#else
	std::cout << "cannot compile move\n";
#endif
}


