#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"


#include <set>
#include <stdexcept>
#include <iterator>


template<typename T,typename CMP=std::less<T>> class indexableSet
:public std::set<T,CMP>{
	using SetType=std::set<T,CMP>;
	using size_type=typename SetType::size_type;
public:
	using std::set<T,CMP>::set;

	T const & operator[](size_type index) const {
		return at(index);
	}
	T const & at(size_type index) const {
		if (index >= SetType::size()) throw std::out_of_range{"indexableSet::operator[] out of range"};
		auto iter=SetType::begin();
		std::advance(iter,index);
		return *iter;
	}
};

template <typename T,typename CMP=std::less<T>>
indexableSet<T,CMP> makeIndexableSet(std::initializer_list<T> li,CMP compare=CMP{}){
	return indexableSet<T,CMP>{li};
}
template <typename ITER, typename CMP=std::less<typename std::iterator_traits<ITER>::value_type>>
auto makeIndexableSetIter(ITER b, ITER e, CMP compare=CMP{})
-> indexableSet<typename std::iterator_traits<ITER>::value_type, CMP> {
	return indexableSet<typename std::iterator_traits<ITER>::value_type, CMP>(b,e);
}

void constructIndexableSet(){
	indexableSet<int> is{};
	ASSERT_EQUAL(0,is.size());
	ASSERT(is.empty());
}
void insertIntoIndexableSetAndIndexIt(){
	indexableSet<int> is{};
	is.insert(42);
	ASSERT_EQUAL(1,is.size());
	ASSERT_EQUAL(42,is[0]);
	ASSERT_EQUAL(42,is.at(0));
	ASSERT_THROWS(is[1],std::out_of_range);
}
void constructIndexableSetFromInitializerList(){
	indexableSet<char> is{'s','a','n','t','a'};
	ASSERT_EQUAL(4,is.size());
	ASSERT_EQUAL('a',is[0]);
	ASSERT_EQUAL('t',is[3]);
}
void constructIndexableSetFromRange(){
	std::string const s{"claus"};
	indexableSet<char> is(s.begin(),s.end());
	std::string t(is.begin(),is.end());
	ASSERT_EQUAL("aclsu",t);
	ASSERT_EQUAL(s.size(),is.size());
	ASSERT_EQUAL('u',is.at(s.size()-1));
	ASSERT_EQUAL('a',is.at(0));
}
void IndexableSetIterators(){
	indexableSet<int> const is{5,4,3,2,1};
	ASSERT_EQUAL(1,*is.cbegin());
	auto it=is.cbegin();
	for (int i{1}; it != is.cend(); ++it, ++i){
		ASSERT_EQUAL(i,*it);
	}
}
void ReverseIteratorsIndexableSet(){
	indexableSet<char> is{'x','m','a','s'};
	ASSERT_EQUAL('x',*is.rbegin());
	std::string s(is.rbegin(),is.rend());
	ASSERT_EQUAL("xsma",s);
	std::string s2{is.crbegin(),is.crend()};
	ASSERT_EQUAL("xsma",s2);
}

void checkFactorySimple(){
	auto is=makeIndexableSet({3,2,1,2,3});
	ASSERT_EQUAL(3,is.size());
	ASSERT_EQUAL(1,*is.begin());
}
void checkFactoryGreaterSort(){
	auto is=makeIndexableSet({1,2,3,2,1},std::greater<int>{});
	ASSERT_EQUAL(3,is.size());
	ASSERT_EQUAL(3,*is.begin());
}
void checkFactoryFromIterators(){
	std::string s{"santaclaus"};
	auto is=makeIndexableSetIter(s.cbegin(),s.cend());
	ASSERT_EQUAL("aclnstu",std::string(is.begin(),is.end()));
}

void insertAndEraseElements(){
	auto is=makeIndexableSet({4,2,3,1});
	ASSERT_EQUAL(4,is.size());
	is.insert(5);
	ASSERT_EQUAL(5,is.size());
	is.insert(5);
	ASSERT_EQUAL(5,is.size());
	is.erase(1);
	ASSERT_EQUAL(4,is.size());
}
void findAndCount(){
	auto is=makeIndexableSet({4,2,3,1});
	ASSERT_EQUAL(is.end(),is.find(42));
	ASSERT_EQUAL(is.begin(),is.find(1));
	ASSERT_EQUAL(0,is.count(42));
	ASSERT_EQUAL(1,is.count(2));
}

void bounds_functions(){
	auto is=makeIndexableSet({4,2,3,1});
	auto p=is.equal_range(3);
	ASSERT_EQUAL(p.first,is.lower_bound(3));
	ASSERT_EQUAL(p.second,is.upper_bound(3));
	ASSERT_EQUAL(3,*p.first);
	ASSERT_EQUAL(4,*p.second);
}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(constructIndexableSet));
	s.push_back(CUTE(insertIntoIndexableSetAndIndexIt));
	s.push_back(CUTE(constructIndexableSetFromInitializerList));
	s.push_back(CUTE(constructIndexableSetFromRange));
	s.push_back(CUTE(IndexableSetIterators));
	s.push_back(CUTE(ReverseIteratorsIndexableSet));
	s.push_back(CUTE(checkFactorySimple));
	s.push_back(CUTE(checkFactoryGreaterSort));
	s.push_back(CUTE(checkFactoryFromIterators));
	s.push_back(CUTE(insertAndEraseElements));
	s.push_back(CUTE(findAndCount));
	s.push_back(CUTE(bounds_functions));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}

