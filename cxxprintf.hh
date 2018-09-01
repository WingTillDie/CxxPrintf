#pragma once
#include <iostream>
#include <cstdarg>
#include <cstdio>

struct putf_r{
	char *s;
};

putf_r putf(const char *fmt, ...);
std::ostream& operator<<(std::ostream& os, putf_r a);

putf_r putf(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	putf_r a;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
	vasprintf(&a.s, fmt, ap);
#pragma GCC diagnostic pop
	va_end(ap);
	return a;
}

std::ostream& operator<<(std::ostream& os, putf_r a){
	os<<a.s;
	free(a.s);
	return os;
}

