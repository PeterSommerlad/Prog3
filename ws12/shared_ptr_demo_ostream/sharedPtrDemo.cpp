#include <memory>
#include <fstream>
#include <sstream>




std::shared_ptr<std::ostream> os_factory(bool str){
    if (str)
        return std::make_shared<std::ostringstream>();
    else
        return std::make_shared<std::ofstream>("hello.txt");
}


int main(){
	auto out = os_factory(false);
	if (out) (*out) << "hello world\n";
	auto fileout = os_factory(true);
	if (fileout) (*fileout) << "Hello, world!\n";
	fileout.reset(); // clears shared_ptr, deallocates stream object
}
