#ifndef PRINTLN_H_
#define PRINTLN_H_
#include <ostream>
// base case overload
void println(std::ostream &out) {
	out << "\n";
}
//variadic template
template<typename Head, typename... Tail>
void println(std::ostream &out, Head const& head, Tail const& ...tail) {
	out << head;
	if (sizeof...(tail)) {
		out << ", ";
		println(out,tail...); //recurse on tail
	} else
		out << '\n';
}

#endif /* PRINTLN_H_ */
