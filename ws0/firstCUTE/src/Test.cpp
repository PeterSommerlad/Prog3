#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

void thisIsATest() {
	auto l=[]{ return true;};
	ASSERTM("start writing tests", l());
}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



