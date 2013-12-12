#include <functional>
#include <iostream>

double f(double x, double y){
	return x / y;
}

void print(std::ostream &out,double x) {
	out << x << '\n';
}

void bind_expressions(){
	using std::cout;
	using namespace std::placeholders;
	auto fix_first = std::bind(f, 1, _1);
	cout << fix_first(2) << '\n'; // f(1,2)
	auto exchange_paramters = std::bind(f, _2,
			_1);
	cout << exchange_paramters(2,1) << '\n'; // f(1,2);
	auto nest_function = bind(f,
			std::bind(f, _1, _2),
			_3);
	cout << nest_function(1,2,3) << '\n'; //f(f(1,2),3);
	auto combined = bind(f, bind(fix_first, _2),_3);
	cout << combined("ignored",2,3) << '\n'; //f(f(1,2),3);

	auto printer = bind(print, std::ref(std::cout), _1);
	printer(42);
	printer(fix_first(2));

}


