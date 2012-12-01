#ifndef FIELD_H_
#define FIELD_H_
#include "is_prime.h"
#include <iosfwd>
#include <boost/operators.hpp>

template<unsigned N>
struct Field
: boost::equality_comparable<Field<N>>
, boost::arithmetic<Field<N>>
{
	static_assert(is_prime<N>::value,"N must be a prime number");
    Field(unsigned x=0u) : val{ x % N } {}
    unsigned value() const { return val; }

    bool operator==(Field const &r) const {
        return val == r.val;
    }
    Field operator+=(Field const &r) {
        val = (val + r.value())%N;
        return *this;
    }
    Field operator-=(Field const &r) {
    	val = (val + (N-r.value()))%N;
    	return *this;
    }
    Field operator*=(Field const&r) {
        val = (val * r.value())%N;
        return *this;
    }
    Field operator/=(Field const&r) {
    	val = (val * r.reciprocal()) %N;
    	return *this;
    }
    explicit
    operator unsigned() const { return val; }
private:
    unsigned val;
    unsigned reciprocal() const {
    	for (unsigned i=1; i < N; ++i){
    		if (1==(val*i)%N) return i;
    	}
    	return 0; // something wrong....
    }
    static_assert(check_prime(N),"template argument must be a prime number");
};

template <unsigned N>
std::ostream& operator <<(std::ostream& out,  Field<N> const& r){
    out << "Field"<<N<<"{"<<r.value()<<'}';
    return out;
}



#endif /* FIELD_H_ */
