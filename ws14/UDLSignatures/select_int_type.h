#ifndef SELECT_INT_TYPE_H_
#define SELECT_INT_TYPE_H_
#include <type_traits>
#include <limits>

namespace std {
namespace select_int_type {

template <unsigned long long val, typename... INTS>
struct select_int_type;

template <unsigned long long val, typename INTTYPE, typename... INTS>
struct select_int_type<val,INTTYPE,INTS...>
:integral_constant<typename conditional<
(val<=static_cast<unsigned long long>(std::numeric_limits<INTTYPE>::max()))
,INTTYPE
,typename select_int_type<val,INTS...>::value_type >::type , val> {
};

template <unsigned long long val>
struct select_int_type<val>:integral_constant<unsigned long long,val>{
};

}}
#endif /* SELECT_INT_TYPE_H_ */
