#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <chrono>
struct move_disabled {
	move_disabled(std::string s, unsigned long i):big(i,s),also_long(s) {
	}
	move_disabled(move_disabled&&)=delete;
	move_disabled& operator=(move_disabled&&)=delete;
	move_disabled(move_disabled const&)=default;
	move_disabled& operator=(move_disabled const&)=default;
private:
	std::vector<std::string> big;
	std::string	also_long;
};
struct move_enabled {
	move_enabled(std::string s, unsigned long i):big(i,s),also_long(s) {
	}
	move_enabled(std::string s, std::vector<std::string> b)
	:big(std::move(b)),also_long(std::move(s)){}
//	move_enabled(move_enabled const&other)
//	:big(other.big)
//	,also_long(other.also_long)
//	{ static bool once=false;
//		if (!once){ once=true; std::cout <<"******copy ctor\n";}
//	}
//	move_enabled(move_enabled&&other)
//	:big(std::move(other.big))
//	,also_long(std::move(other.also_long)){}
//	move_enabled& operator=(move_enabled &&other){
//		big.swap(other.big);
//		also_long.swap(other.also_long);
//		return *this;
//	}
	move_enabled(move_enabled&&)=default;
	move_enabled& operator=(move_enabled &&)=default;
private:
	std::vector<std::string> big;
	std::string	also_long;
};

void testWriting3Times() {
	move_enabled m(std::string(100000u,'a'),1000UL);
	std::vector<move_enabled> vm;
	using Clock=std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    Clock::time_point t0 = Clock::now();
	for (int i=0; i < 10000; ++ i){
//		vm.push_back(move_enabled(std::string(100000u,'a'),1000UL));
		move_enabled m1(std::string(100000u,'a'),1000UL);
		vm.emplace(vm.end(),std::move(m1) );
	}
	std::vector<move_enabled> vm1;
	vm1=std::move(vm);
    Clock::time_point t1 = Clock::now();
    milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
    std::cout << ms.count() << "ms\n";

	ASSERT_EQUAL(100000,vm1.size());

}
void thisIsATest1() {
	move_disabled m(std::string(100000u,'a'),1000UL);
	std::vector<move_disabled> vm;
	using Clock=std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    Clock::time_point t0 = Clock::now();
	for (int i=0; i < 10000; ++ i){
		move_disabled m(std::string(100000u,'a'),1000UL);
		vm.push_back(m);
	}
	std::vector<move_disabled> vm1;
	vm1=std::move(vm);
	Clock::time_point t1 = Clock::now();
    milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
    std::cout << ms.count() << "ms\n";

	ASSERT_EQUAL(100000,vm1.size());
}


void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testWriting3Times));
	s.push_back(CUTE(thisIsATest1));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



