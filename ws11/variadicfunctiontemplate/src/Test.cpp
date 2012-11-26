#include "println.h"
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <iostream>

template <typename... ARGS>
void variadic(ARGS... args){
	println(std::cout,args...);
}



void testVariadicPrint(){
	std::ostringstream out{};
	println(out,1,2,3,"hello",' ',"world");
	ASSERT_EQUAL("1, 2, 3, hello,  , world\n",out.str());
}
void showVariadic(){
	variadic(1,2,3);
	variadic();
	variadic("eins",2,3.0);
	ASSERTM("dummy assert", true);
}


void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testVariadicPrint));
	s.push_back(CUTE(showVariadic));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



