#ifndef IntInputterPtrBoost_H_
#define IntInputterPtrBoost_H_
#include <iosfwd>
#include <boost/operators.hpp>


struct IntInputterPtrBoost
:boost::input_iterator_helper<IntInputterPtrBoost,int>{
	IntInputterPtrBoost() = default;
	explicit IntInputterPtrBoost(std::istream& in)
	:input(&in){}
	IntInputterPtrBoost::value_type operator *();
	IntInputterPtrBoost& operator++(){
		return *this;
	}
	bool operator ==(const IntInputterPtrBoost& other) const;
private:
	std::istream *input{};
};
#endif /* IntInputterPtrBoost_H_ */
