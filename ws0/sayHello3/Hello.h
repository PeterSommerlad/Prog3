#ifndef HELLO_H_
#define HELLO_H
#include <iosfwd>
struct Hello {
	void sayHello(std::ostream &out) const;
};
#endif /* HELLO_H_ */
