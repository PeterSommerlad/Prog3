#include "IntInputterPtrBoost.h"
#include <sstream>

IntInputterPtrBoost::value_type IntInputterPtrBoost::operator *() {
	value_type value { };
	if (input)
		(*input) >> value;
	return value;
}

bool IntInputterPtrBoost::operator==(const IntInputterPtrBoost& other) const {
	return (!input || !input->good()) &&
			(!other.input || !other.input->good());
}
