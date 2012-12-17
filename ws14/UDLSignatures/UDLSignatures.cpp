namespace distance_in_meters {
constexpr double operator"" _m(long double x){
	return x;
}
constexpr double operator"" _m(unsigned long long x){
	return x;
}
}
#include <string>
namespace mystring{
std::string operator"" _s(char const *s, std::size_t len){
	return std::string{s,len};
}
}
namespace mystring{
std::string operator"" _s(char const *s){
	return std::string{s};
}
}
#include <stdexcept>
#include <cstring>
namespace ternary{
unsigned long long operator"" _3(char const *s){
	size_t convertedupto;
	auto res=std::stoull(s, &convertedupto,3u);
	if(convertedupto != strlen(s)) throw std::logic_error{"invalid ternary"};
	return res;
}
}

namespace ternary{
namespace _impl{
template <char... Digits>
struct parse_ternary;
template <char... Digits>
struct parse_ternary<'0',Digits...>{
	static unsigned long long const value{parse_ternary<Digits...>::value};
};
constexpr unsigned long long
three_to(std::size_t power){
	return power?3ull*three_to(power-1):1ull;
}
template <char... Digits>
struct parse_ternary<'1',Digits...>{
	static unsigned long long const value{1 * three_to(sizeof...(Digits))+parse_ternary<Digits...>::value};
};
template <char... Digits>
struct parse_ternary<'2',Digits...>{
	static unsigned long long const value{2 * three_to(sizeof...(Digits))+parse_ternary<Digits...>::value};
};
template <>
struct parse_ternary<>{
	static unsigned long long const value{0};
};
}
}
namespace ternary {
template <char... Digits>
constexpr unsigned long long
operator"" _ternary(){
	return _impl::parse_ternary<Digits...>::value;
}
}
#include <iostream>

int main(){
	using namespace distance_in_meters;
	auto base=5_m;
	auto height=0.5_m;
	std::cout << "triangle area: "<< base/2*height<<" square meters\n";
	using namespace mystring;
	auto s="hello"_s;
	s += " world\n";
	std::cout << s;

	auto rs=42_s;
	rs+=" raw\n";
	std::cout << rs;
	using namespace ternary;
	int four=11_3;
	std::cout << "four is "<<four<<'\n';
	try { four=14_3;// throws
	} catch(std::exception const &e){
		std::cout << e.what() << '\n';
	}

	auto constexpr five=12_ternary;
	std::cout << "five is "<<five<<'\n';
}
