#ifndef IS_PRIME_H_
#define IS_PRIME_H_

namespace __detail{
constexpr bool is_prime_up_to(unsigned check, unsigned limit){
	return check % limit? ((limit * limit < check)?is_prime_up_to(check,limit+1):true):check==limit;
}
}
constexpr bool check_prime(unsigned prime){ return __detail::is_prime_up_to(prime,2);}


namespace detail{
template <unsigned check,unsigned limit>
struct find_divisor{
	static_assert(limit<check,"check to small, no prime");
	static bool const value = (check % limit?
			find_divisor<check,(limit*limit<=check?limit+1:check)>::value:false);
};

template <unsigned check>
struct find_divisor<check,check>{
	static bool const value = true;
};
}

template <unsigned n>
struct is_prime{
	static bool const value = detail::find_divisor<n,2>::value;
};
template <>
struct is_prime<0>{
	static bool const value=false;
};
template <>
struct is_prime<1>{
	static bool const value=false;
};

#endif /* IS_PRIME_H_ */
