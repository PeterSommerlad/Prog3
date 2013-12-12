#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
template<typename ITER>
void show(ITER const &b, ITER e, std::ostream& os) {
	std::ostream_iterator<int> out(os,", ");
	copy(b, e, out);
	os << '\n';
}
int main(){
  std::vector<int> const v{3,1,4,1,5,9,2,6};
  std::vector<int> const s{4,1,5,6};
  using std::cout;
  show(v.begin(),v.end(),cout);
  show(s.begin(),s.end(),cout);
  auto
    start=search(v.begin(),v.end(),s.begin(),s.end()-1);
  show(v.begin(),start,cout);
  if (distance(start,v.end())>= distance(s.begin(),s.end())){
	  auto p=mismatch(start,v.end(),s.begin());
  	  show(p.first,v.end(),cout);
  	  show(p.second,s.end(),cout);
  } else {
	  auto p=mismatch(s.begin(),s.end(),start);
  	  show(p.first,s.end(),cout);
  	  show(p.second,v.end(),cout);
  }
}
