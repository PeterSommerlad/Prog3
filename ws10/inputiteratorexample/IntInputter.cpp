#include "IntInputter.h"
#include <sstream>
namespace {
std::istringstream empty{}; // a global helper needed...
}
IntInputter::IntInputter() :
		input(empty) {
	input.clear(std::ios_base::eofbit);
	// guarantee it is not good()
}

IntInputter::value_type IntInputter::operator *() {
	value_type value{};
	input >> value;
	return value;
}

bool IntInputter::operator ==(const IntInputter& other) const {
	return !input.good() && !other.input.good();
}
