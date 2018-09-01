#include <iostream>
#include <cfloat>
#include "cxxprintf.hh"

int main(){
	std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
	std::cerr << putf("%Le\n", LDBL_MAX) << putf("%p", NULL);
}
