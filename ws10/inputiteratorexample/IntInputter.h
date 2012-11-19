#ifndef IntInputter_H_
#define IntInputter_H_
#include <iosfwd>
#include <iterator>

struct IntInputter
:std::iterator<std::input_iterator_tag,int>{
	IntInputter();
	explicit IntInputter(std::istream& in)
	:input(in){} // must use () for references, bug in C++11 standard
	value_type operator *();
	IntInputter& operator++(){
		return *this;
	}
	IntInputter operator++(int){
		IntInputter old{*this};
		++(*this);
		return old;
	}
	bool operator ==(const IntInputter& other) const;
	bool operator!=(IntInputter const &other) const{
		return !(*this == other);
	}
private:
	std::istream &input;
};
#endif /* IntInputter_H_ */
