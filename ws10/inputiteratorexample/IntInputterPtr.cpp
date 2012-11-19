#include "IntInputterPtr.h"
#include <sstream>

IntInputterPtr::value_type IntInputterPtr::operator *() {
	value_type value { };
	if (input)
		(*input) >> value;
	return value;
}

bool IntInputterPtr::operator==(const IntInputterPtr& other) const {
	return (!input || !input->good()) &&
			(!other.input || !other.input->good());
}
