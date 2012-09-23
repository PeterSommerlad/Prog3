#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <sstream>
int inputAge(std::istream& in); // do not change anything, line numbers are important
void testAgeInputEOF() {
	std::istringstream in;
	ASSERT_EQUAL(-1, inputAge(in));
}
void testAgeInputOK() {
	std::istringstream in{"42\n"};
	ASSERT_EQUAL(42, inputAge(in));
}
void testAgeInputWrong() {
	std::istringstream in{"wrong \n"};
	ASSERT_EQUAL(-1, inputAge(in));
	ASSERT(in.eof());
}
void testAgeInputSeveralWrongLinesThenOK() {
	std::istringstream in{"wrong \n\n 42\n"};
	ASSERT_EQUAL(42, inputAge(in));
}

void testAgeInputEOF1() {
	std::istringstream in;
	ASSERT_EQUAL(-1, inputAge(in));
}
void testAgeInputWrong3() {
	std::istringstream in{"wrong \n"};
	ASSERT_EQUAL(-1,inputAge(in));
	ASSERT(in.eof());
}
void testAgeInputLastLineReadCompletely() {
	std::istringstream in{"wrong \n\n 42 ignored\n"};
	ASSERT_EQUAL(42, inputAge(in));
	ASSERT(in);
	in.get();
	ASSERT(in.eof());
}
int inputAge(std::istream& in) {
	while (in) {
		std::string line{};
		getline(in, line);
		try{
		    return stoi(line);
		} catch (...){}
	}
	return -1;
}

void runSuite() {
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testAgeInputEOF));
	s.push_back(CUTE(testAgeInputOK));
	s.push_back(CUTE(testAgeInputSeveralWrongLinesThenOK));
	s.push_back(CUTE(testAgeInputEOF1));
	s.push_back(CUTE(testAgeInputLastLineReadCompletely));
	s.push_back(CUTE(testAgeInputWrong));
	s.push_back(CUTE(testAgeInputWrong3));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}
int main() {
	runSuite();
	return 0;
}

