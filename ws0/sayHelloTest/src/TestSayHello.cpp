#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <sstream>
#include "sayHello2.h"
void testSayHelloSaysHelloWorld() {
	std::ostringstream out;
	sayHello(out);
	ASSERT_EQUAL("Hello world!\n",out.str());
}
void runSuite(){
	cute::suite s;
	s.push_back(CUTE(testSayHelloSaysHelloWorld));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}
int main(){
    runSuite();
}


