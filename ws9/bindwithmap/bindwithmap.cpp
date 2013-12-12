#include <unordered_map>
#include <functional>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
using wlist=std::unordered_map<std::string,size_t>;
using Pair=std::pair<std::string,size_t>;

void printtopten2(wlist const &wm){
	using namespace std::placeholders;
	std::vector<Pair> wf{wm.begin(),wm.end()};
	std::vector<Pair> topten(10);
	partial_sort_copy(wf.cbegin(),wf.cend(),
			topten.begin(),topten.end(),
			bind(std::greater<std::size_t>{},
				 bind(&Pair::second,_1),
				 bind(&Pair::second,_2)));
	using out=std::ostream_iterator<std::string>;
	transform(topten.begin(),topten.end(),
			out{std::cout,"\n"},bind(&Pair::first,_1));
}
#if 0

void printtopten(wlist const &wm){
	using namespace std::placeholders;
	std::vector<Pair> topten(10);
	partial_sort_copy(wm.cbegin(),wm.cend(),
			topten.begin(),topten.end(),
			bind(std::greater<std::size_t>{},
				 bind(&Pair::second,_1),
				 bind(&Pair::second,_2)));
	using out=std::ostream_iterator<std::string>;
	transform(topten.begin(),topten.end(),
			out{std::cout,"\n"},bind(&Pair::first,_1));
}
#else
void printtopten(wlist const &wm){
	using namespace std::placeholders;
	std::vector<Pair> topten(10);
	std::function<bool(Pair const&, Pair const&)> const cmp=
			bind(std::greater<std::size_t>{},
				 bind(&Pair::second,_1),
				 bind(&Pair::second,_2));

	partial_sort_copy(wm.cbegin(),wm.cend(),
			topten.begin(),topten.end(),
			cmp);

	using out=std::ostream_iterator<std::string>;
	transform(topten.begin(),topten.end(),
			out{std::cout,"\n"},bind(&Pair::first,_1));
}
#endif
void printtop_n(wlist& wm,size_t n) {
	using namespace std::placeholders;
	std::vector<Pair> wf { wm.begin(), wm.end() };
	stable_sort(wf.begin(), wf.end(),
			bind(std::greater<size_t> { }, bind(&Pair::second, _1),
					bind(&Pair::second, _2)));
	using out = std::ostream_iterator<std::string>;
	transform(wf.begin(), min(wf.begin() + n, wf.end()),
			out { std::cout, "\n" }, bind(&Pair::first, _1));
}

int main(){
	wlist wm{};
	std::string w;
	while(std::cin >> w){
		wm[w]++;
	}
	printtopten(wm);
	printtop_n(wm,10);
}

//[](Pair l, Pair r){return l.second > r.second;});

