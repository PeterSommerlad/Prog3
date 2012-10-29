#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/bind.hpp>
template <typename K, typename V>
struct key:std::unary_function<std::pair<K,V>const &,K>{
	K const &operator()(std::pair<K,V>const &p)const{
		return p.first;
	}
};
template <typename K, typename V>
struct value:std::unary_function<std::pair<K,V>const &,V>{
	V const &operator()(std::pair<K,V>const &p)const{
		return p.second;
	}
};

int main(){
typedef std::map<std::string,int> wordmap;
wordmap words;
std::string s;
while (std::cin >> s)
		++words[s];




typedef wordmap::const_iterator iter;
for(iter it=words.begin(); it!=words.end(); ++it)
  std::cout << it->first << " = "<< it->second << '\n';


key<wordmap::key_type,int> const selKey;
std::ostream_iterator<std::string> outstr(std::cout,", ");
transform(words.begin(),words.end(),outstr,selKey);
std::cout << "\n";
copy(boost::make_transform_iterator(words.begin(),selKey),
	 boost::make_transform_iterator(words.end(),selKey),
	 outstr);
std::cout << "\n";
transform(words.begin(),words.end(),outstr,
		 boost::bind(&wordmap::value_type::first,_1));
std::cout << "\n";

value<wordmap::key_type,int> const selectVal;
copy(boost::make_transform_iterator(words.begin(),selectVal),
	 boost::make_transform_iterator(words.end(),selectVal),
	 std::ostream_iterator<int>(std::cout,", "));

auto selkey=boost::bind(&wordmap::value_type::first,_1);
copy(boost::make_transform_iterator(words.begin(),selkey),
	 boost::make_transform_iterator(words.end(),selkey),
	 outstr);


}
