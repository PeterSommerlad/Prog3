#ifndef SUFFIXESPARSENUMBERS_H_
#define SUFFIXESPARSENUMBERS_H_
#include <cstddef>
namespace std {
namespace parse_int {
template <unsigned base, char... Digits>
struct parse_int{
    static_assert(base<=16u,"only support up to hexadecimal");
    static_assert(! sizeof...(Digits), "invalid integral constant");
    static constexpr unsigned long long value=0;
};

template <char... Digits>
struct base_dispatch;

template <char... Digits>
struct base_dispatch<'0','x',Digits...>{
    static constexpr unsigned long long value=parse_int<16u,Digits...>::value;
};
template <char... Digits>
struct base_dispatch<'0','X',Digits...>{
    static constexpr unsigned long long value=parse_int<16u,Digits...>::value;
};
template <char... Digits>
struct base_dispatch<'0',Digits...>{
    static constexpr unsigned long long value=parse_int<8u,Digits...>::value;
};
template <char... Digits>
struct base_dispatch{
    static constexpr unsigned long long value=parse_int<10u,Digits...>::value;
};

constexpr unsigned long long
pow(unsigned base, size_t to) {
    return to?(to%2?base:1)*pow(base,to/2)*pow(base,to/2):1;
}

template <unsigned base, char... Digits>
struct parse_int<base,'0',Digits...>{
    static constexpr unsigned long long value{ parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'1',Digits...>{
    static constexpr unsigned long long value{ 1 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'2',Digits...>{
    static_assert(base>2,"invalid digit");
    static constexpr unsigned long long value{ 2 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'3',Digits...>{
    static_assert(base>3,"invalid digit");
    static constexpr unsigned long long value{ 3 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'4',Digits...>{
    static_assert(base>4,"invalid digit");
    static constexpr unsigned long long value{ 4 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'5',Digits...>{
    static_assert(base>5,"invalid digit");
    static constexpr unsigned long long value{ 5 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'6',Digits...>{
    static_assert(base>6,"invalid digit");
    static constexpr unsigned long long value{ 6 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'7',Digits...>{
    static_assert(base>7,"invalid digit");
    static constexpr unsigned long long value{ 7 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'8',Digits...>{
    static_assert(base>8,"invalid digit");
    static constexpr unsigned long long value{ 8 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'9',Digits...>{
    static_assert(base>9,"invalid digit");
    static constexpr unsigned long long value{ 9 *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'a',Digits...>{
    static_assert(base>0xa,"invalid digit");

    static constexpr unsigned long long value{ 0xa *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'b',Digits...>{
    static_assert(base>0xb,"invalid digit");
    static constexpr unsigned long long value{ 0xb *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'c',Digits...>{
    static_assert(base>0xc,"invalid digit");
    static constexpr unsigned long long value{ 0xc *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'d',Digits...>{
    static_assert(base>0xd,"invalid digit");
    static constexpr unsigned long long value{ 0xd *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'e',Digits...>{
    static_assert(base>0xe,"invalid digit");
    static constexpr unsigned long long value{ 0xe *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'f',Digits...>{
    static_assert(base>0xf,"invalid digit");
    static constexpr unsigned long long value{ 0xf *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'A',Digits...>{
    static_assert(base>0xA,"invalid digit");
    static constexpr unsigned long long value{ 0xa *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'B',Digits...>{
    static_assert(base>0xB,"invalid digit");
    static constexpr unsigned long long value{ 0xb *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'C',Digits...>{
    static_assert(base>0xC,"invalid digit");
    static constexpr unsigned long long value{ 0xc *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'D',Digits...>{
    static_assert(base>0xD,"invalid digit");
    static constexpr unsigned long long value{ 0xd *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'E',Digits...>{
    static_assert(base>0xE,"invalid digit");
    static constexpr unsigned long long value{ 0xe *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
template <unsigned base, char... Digits>
struct parse_int<base,'F',Digits...>{
    static_assert(base>0xF,"invalid digit");
    static constexpr unsigned long long value{ 0xf *pow(base,sizeof...(Digits))
                                               + parse_int<base,Digits...>::value};
};
}}
#endif /* SUFFIXESPARSENUMBERS_H_ */
