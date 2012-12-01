#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Field.h"
using Field5=Field<5>;
void testDefaultCtor() {
    Field5 v{};
    ASSERT_EQUAL(0,v.value());
}
void testValueCtor(){
    Field5 four{4};
    ASSERT_EQUAL(4,four.value());
}
// operator==, operator<< for failures
void testValueCtorWithLargeInput(){
    Field5 four{19};
    ASSERT_EQUAL(Field5{4},four);
}
// define operator<< format
void testOutputOperator(){
    std::ostringstream out;
    out << Field5{4};
    ASSERT_EQUAL("Field5{4}",out.str());
}

void testAddition() {
    Field5 two{2};
    Field5 four = two+two;
    ASSERT_EQUAL(4,four.value());
}
void testAdditionWrap(){
    Field5 four{4};
    Field5 three = four + four;
    ASSERT_EQUAL(3,three.value());
}

void testMultiplication(){
    Field5 four{4};
    Field5 three{3};
    Field5 two = four * three;
    ASSERT_EQUAL(Field5{2},two);
}

void testDivision(){
	Field5 three{3};
	Field5 two{2};
	Field5 four{4};
	ASSERT_EQUAL(Field5{4},three/two);
	ASSERT_EQUAL(three,Field5{1}/two);
	ASSERT_EQUAL(two,Field5{1}/three);
	ASSERT_EQUAL(four,Field5{1}/four);
}

void testis_prime_trait(){
	ASSERT(is_prime<2>::value);
	ASSERT(!is_prime<42>::value);
	ASSERT(is_prime<41>::value);
	// compile checks
	//Field<42> doesntcompile{};
	Field<43> shouldcompile{};

}








void testAdditionWithInt(){
//*
    Field5 two{2};
    auto four=two+2u;
    ASSERT_EQUAL(Field5{4},four);
    ASSERT_EQUAL(typeid(Field5).name(),
                 typeid(decltype(four)).name());
//*/
}

void testAssignmentBackToInt(){
    Field5 three{8};
    unsigned u3(three);
/*
    unsigned eight= three+5u;
    ASSERT_EQUAL(8u,eight);
//*/
    ASSERT_EQUAL(3u,u3);
}

void testAdditionWithIntExplicitCtor(){
    Field5 two{2};
    auto four=two+Field5{2u};
    ASSERT_EQUAL(Field5{4},four);
    ASSERT_EQUAL(typeid(Field5).name(),
                 typeid(decltype(four)).name());
}



void testAssignmentBackToIntExplicitCtor(){
    Field5 three{8};
/*    unsigned u3=three;
    auto eight= three+5u;
    ASSERT_EQUAL(8u,eight);
    ASSERT_EQUAL(3u,u3);
    ASSERT_EQUAL(3u,three);
*/}



void runSuite(){
    cute::suite s;
    //TODO add your test here
    s.push_back(CUTE(testDefaultCtor));
    s.push_back(CUTE(testValueCtor));
    s.push_back(CUTE(testValueCtorWithLargeInput));
    s.push_back(CUTE(testAddition));
    s.push_back(CUTE(testAdditionWrap));
    s.push_back(CUTE(testOutputOperator));
    s.push_back(CUTE(testMultiplication));
    s.push_back(CUTE(testAdditionWithInt));
    s.push_back(CUTE(testAssignmentBackToInt));
    s.push_back(CUTE(testAdditionWithIntExplicitCtor));
    s.push_back(CUTE(testAssignmentBackToIntExplicitCtor));
	s.push_back(CUTE(testDivision));
	s.push_back(CUTE(testis_prime_trait));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



