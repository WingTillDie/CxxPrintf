#pragma once
struct putf_r{
	char *s;
};

putf_r putf(const char *fmt, ...);
std::ostream& operator<<(std::ostream& os, putf_r a);
