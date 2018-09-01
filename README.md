# CxxPrintf
C++ printf-like formatting for std::cout implemented using vasprintf()
  
## Usage
```C++
#include "cxxprintf.hh"
std::cout << putf(const char *format, ...); //Same format as C printf(3)
```
### Example
```C++
std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
```
Output on stdout:
```
 23
0x1p+8

```
## Description
This header file implement C printf-like formatting for C++ std::cout using vasprintf() from stdio.h.  
This header file acheive the feature using relative short code compared to other methods like boost::format or std::experimental::putf, see [related thread on StackOverflow](https://stackoverflow.com/questions/15106102/how-to-use-c-stdostream-with-printf-like-formatting#15106194).
