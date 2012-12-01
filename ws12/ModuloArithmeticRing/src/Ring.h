#ifndef RING_H_
#define RING_H_

#include <iosfwd>
#include <boost/operators.hpp>

template<unsigned N>
struct Ring : boost::equality_comparable<Ring<N>>
, boost::ring_operators<Ring<N>>
{
    Ring(unsigned x=0u) : val{ x % N } {}
    unsigned value() const { return val; }
    bool operator==(Ring const &r) const {
        return val == r.val;
    }
    Ring operator+=(Ring const &r) {
        val = (val + r.value())%N;
        return *this;
    }
    Ring operator-=(Ring const &r) {
    	val = (val + (N-r.value()))%N;
    	return *this;
    }
    Ring operator*=(Ring const&r) {
        val = (val * r.value())%N;
        return *this;
    }
    explicit operator unsigned() const { return val; }
private:
    unsigned val;
};

template <unsigned N>
std::ostream& operator <<(std::ostream& out,  Ring<N> const& r){
    out << "Ring"<<N<<"{"<<r.value()<<'}';
    return out;
}



#endif /* RING_H_ */
