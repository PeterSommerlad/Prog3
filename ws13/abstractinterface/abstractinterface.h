#ifndef ABSTRACTINTERFACE_H_
#define ABSTRACTINTERFACE_H_

struct abstractinterface{
	virtual int func(int) const =0;
};


void doit(abstractinterface const &);

#endif /* ABSTRACTINTERFACE_H_ */
