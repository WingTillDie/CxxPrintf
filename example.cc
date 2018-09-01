#include <iostream>
#include "cxxprintf.hh"

class ostreamf{
private:
	std::ostream *osp;
public:
	ostreamf(std::ostream &os_in){osp=&os_in;}
	auto operator()(const char *fmt, ...){
		*osp<<fmt;
		return osp;
	}
};

int main(){
	std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
	std::cerr << putf("%Le\n", DBL_MAX) << putf("%p", NULL);
	ostreamf coutf(std::cout);//How to receive from cout
	coutf("test");
}
