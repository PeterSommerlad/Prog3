#include "Ring5.h"
#include <ostream>







std::ostream& operator <<(std::ostream& out, Ring5 const& r) {
    out << "Ring5{"<<r.value()<<'}';
    return out;
}
