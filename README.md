# CxxPrintf
C++ printf-like formatting for std::ostream implemented via vasprintf()
  
## Usage
```C++
#include "cxxprintf.hh"
std::cout << putf(const char *format, ...); //Same format as C printf(3)
```
### Example
See [example.cc](example.cc)
```C++
std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
std::cerr << putf("%Le\n", LDBL_MAX) << putf("%p", NULL);
```
Output on stdout:
```
 23
0x1p+8
1.797693e+308
0x0

```
### Caveat
Compiler warning flag -Wformat-nonliteral doesn't check format in putf, so take care of [uncontrolled format string](https://en.m.wikipedia.org/wiki/Uncontrolled_format_string) vulnerability by yourself. 
## Description
This header file implement C printf-like formatting for C++ std::cout using vasprintf() from stdio.h.  
This header file acheive the feature using relative short code compared to other methods like boost::format or std::experimental::putf, see [related thread on StackOverflow](https://stackoverflow.com/questions/15106102/how-to-use-c-stdostream-with-printf-like-formatting#15106194).
