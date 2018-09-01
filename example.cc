#include <iostream>
#include "cxxprintf.hh"

int main(){
	std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
}
