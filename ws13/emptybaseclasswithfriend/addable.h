#ifndef ADDABLE_H_
#define ADDABLE_H_

template <typename T>
struct addable {
	// free function not a member function
	friend T operator+(T l, T const &r ){
		return l+=r;
	}
};

#endif /* ADDABLE_H_ */
