
class Base {
public:
	Base()=default;
	Base(int){}
};
class Derived: public Base{};

class DerivedPrivateBase : Base {};

struct DerivedPublicBase: Base{};


struct MixIn{};

class MultipleBases: public Base, private MixIn {};


class DerivedWithCtor: public Base{
	DerivedWithCtor():Base{} {}

	DerivedWithCtor(DerivedWithCtor const &){
		// this is wrong, Base not copied!
	}

	DerivedWithCtor(int i, int j)
	: Base{i}, mvar{j} {}

	DerivedWithCtor(int i)
	: DerivedWithCtor(i,i) {}

	int mvar{};
};


struct ABase {
	virtual ~ABase(){}
	virtual void doit(){}
};
class Concrete: public ABase {
	void doit() { /* differently */}
};

struct AbstractBase {
	virtual ~AbstractBase(){}
	virtual void doitnow()=0;
};

class Multiple:public ABase, public AbstractBase {

};

class PolymorphicBase {
public:
	virtual void doit() { /* something*/ }
};

class Implementor: public PolymorphicBase {
public:
	void doit() {
          /* something else */
       }
};


int main(){
	Implemetor impl;
	PolymorphicBase &pbref=impl;
	pbref.doit();
}



