#ifndef BINARY_H_
#define BINARY_H_
#include <limits>
#include <type_traits>
#include "select_int_type.h"
namespace std{
namespace suffixes{
namespace binary{
namespace __impl{

template <char... Digits>
struct bitsImpl{
	static_assert(! sizeof...(Digits),
			"binary literal digits must be 0 or 1");
	static constexpr unsigned long long value=0;
};

template <char... Digits>
struct bitsImpl<'0',Digits...>{
	static constexpr unsigned long long value=bitsImpl<Digits...>::value;
};

template <char... Digits>
struct bitsImpl<'1',Digits...>{
	static constexpr unsigned long long value=
			bitsImpl<Digits...>::value|(1ULL<<sizeof...(Digits));
};
using std::select_int_type::select_int_type;
}


template <char... Digits>
constexpr typename
__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
      int, unsigned, long, unsigned long, long long>::value_type
operator"" b(){
	return	__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
			int, unsigned, long, unsigned long, long long>::value;
}
template <char... Digits>
constexpr typename
__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
      long, unsigned long, long long>::value_type
operator"" bl(){
	return	__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
			      long, unsigned long, long long>::value;
}
template <char... Digits>
constexpr auto
operator"" bL() -> decltype(operator "" bl<Digits...>()){
	return 	operator "" bl<Digits...>();
}

template <char... Digits>
constexpr typename
__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
       long long>::value_type
operator"" bll(){
	return 	__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
			      long long>::value;
}
template <char... Digits>
constexpr auto
operator"" bLL() -> decltype(operator "" bll<Digits...>()){
	return 	operator "" bll<Digits...>();
}

template <char... Digits>
constexpr typename
__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
      unsigned, unsigned long>::value_type
operator"" bu(){
	return 	__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
			      unsigned, unsigned long>::value;
}

template <char... Digits>
constexpr auto
operator"" bU() -> decltype(operator "" bu<Digits...>()){
	return 	operator "" bu<Digits...>();
}

template <char... Digits>
constexpr typename
__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
       unsigned long>::value_type
operator"" bul(){
	return 	__impl::select_int_type<__impl::bitsImpl<Digits...>::value,
			      unsigned long>::value;
}
template <char... Digits>
constexpr auto
operator"" bUL() -> decltype(operator "" bul<Digits...>()){
	return 	operator "" bul<Digits...>();
}
template <char... Digits>
constexpr auto
operator"" buL() -> decltype(operator "" bul<Digits...>()){
	return 	operator "" bul<Digits...>();
}
template <char... Digits>
constexpr auto
operator"" bUl() -> decltype(operator "" bul<Digits...>()){
	return 	operator "" bul<Digits...>();
}
template <char... Digits>
constexpr unsigned long long
operator"" bull(){
	return __impl::bitsImpl<Digits...>::value;
}
template <char... Digits>
constexpr unsigned long long
operator"" bULL(){
	return __impl::bitsImpl<Digits...>::value;
}
template <char... Digits>
constexpr unsigned long long
operator"" buLL(){
	return __impl::bitsImpl<Digits...>::value;
}
template <char... Digits>
constexpr unsigned long long
operator"" bUll(){
	return __impl::bitsImpl<Digits...>::value;
}


} // binary
} //suffixes
} // std



#endif /* BINARY_H_ */
