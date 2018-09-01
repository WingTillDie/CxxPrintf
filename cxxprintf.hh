#pragma once
#include <iostream>

struct putf_r{
	char *s;
};

putf_r putf(const char* fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	putf_r a;
	vasprintf(&a.s, fmt, ap);
	va_end(ap);
	return a;
}

auto& operator<<(std::ostream& os, putf_r a){
	std::cout<<a.s;
	free(a.s);
	return os;
}

