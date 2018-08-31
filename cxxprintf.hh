#pragma once
#include <iostream>

struct putf_r{
	char *s;
};

putf_r putf(const char* fmt, ...){
	va_list ap;
	putf_r a;
	va_start(ap, fmt);
	vasprintf(&a.s, fmt, ap);
	return a;
}

auto& operator<<(std::ostream& os, putf_r a){
	std::cout<<a.s;
	free(a.s);
	return os;
}

