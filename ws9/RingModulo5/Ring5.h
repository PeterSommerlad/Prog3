#ifndef RING5_H_
#define RING5_H_
#include <iosfwd>
#include <boost/operators.hpp>





struct Ring5
: boost::equality_comparable<Ring5>
, boost::addable<Ring5>



{
//...
    explicit
//
    Ring5(unsigned x=0u) : val{ x % 5 } {}
    unsigned value() const { return val; }

    bool operator==(Ring5 const &r) const {
        return val == r.val;
    }
    Ring5 operator+=(Ring5 const &r) {
        val = (val + r.value())%5;
        return *this;
    }
    Ring5 operator*=(Ring5 const&r) {
        val = (val * r.value())%5;
        return *this;
    }






private:
    unsigned val;
};

inline Ring5 operator*(Ring5 l, Ring5 const &r){
     l *= r;
     return l;
}


std::ostream& operator <<(std::ostream& out, Ring5 const& r);


#endif /* RING5_H_ */
