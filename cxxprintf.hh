#pragma once
#include <iostream>

#pragma clang diagnostic warning "-Weverything"

struct putf_r{
	char *s;
};

putf_r putf(const char *fmt, ...);
std::ostream& operator<<(std::ostream& os, putf_r a);

putf_r putf(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	putf_r a;
	vasprintf(&a.s, fmt, ap);
	va_end(ap);
	return a;
}

std::ostream& operator<<(std::ostream& os, putf_r a){
	os<<a.s;
	free(a.s);
	return os;
}

