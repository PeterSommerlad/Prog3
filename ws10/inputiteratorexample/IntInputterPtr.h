#ifndef IntInputterPtr_H_
#define IntInputterPtr_H_
#include <iosfwd>
#include <iterator>

struct IntInputterPtr
:std::iterator<std::input_iterator_tag,int>{
	IntInputterPtr() = default;
	explicit IntInputterPtr(std::istream& in)
	:input(&in){}
	IntInputterPtr::value_type operator *();
	IntInputterPtr& operator++(){
		return *this;
	}
	IntInputterPtr operator++(int){
		IntInputterPtr old{*this};
		++(*this);
		return old;
	}
	bool operator ==(const IntInputterPtr& other) const;
	bool operator!=(IntInputterPtr const &other) const{
		return !(*this == other);
	}
private:
	std::istream *input{};
};
#endif /* IntInputterPtr_H_ */
