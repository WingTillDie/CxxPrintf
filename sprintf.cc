#include <iostream>

struct putf_r{
	char *s;
};

namespace std{
putf_r putf(const char* fmt, ...){
	va_list ap;
	putf_r a;
	va_start(ap, fmt);
	vasprintf(&a.s, fmt, ap);
	return a;
}
}
auto& operator<<(std::ostream& os, putf_r a){
	std::cout<<a.s;
	free(a.s);
	return os;
}

int main(){
	std::cout << std::putf("%3d", 23);
}
