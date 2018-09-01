# CxxPrintf
C++ printf-like formatting for std::ostream implemented via vasprintf()
  
## Usage
Copy cxxprintf.a and cxxprintf.hh to the directory containing the source file that uses it  
  
Include header file cxxprintf.hh in your source code:  
```C++
#include "cxxprintf.hh"
```
Use the function putf() with following format:  
```C++
std::ostream << putf(const char *format, ...); //Same format as C printf(3)
```
Then link with cxxprintf.a when compiling  
### Example
See [example.cc](example.cc)
```C++
std::cout << putf("%3d\n", 23) << putf("%a\n", 256.);
std::cerr << putf("%Le\n", LDBL_MAX) << putf("%p", NULL);
```
Compile with linking to cxxprintf.a:  
```bash
g++ example.cc cxxprintf.a
```
Sample output on stdout (on x86_64 machine):
```
 23
0x1p+8
1.189731e+4932
0x0

```
### Caveat
Compiler warning flag -Wformat-nonliteral doesn't check format in putf, so take care of [uncontrolled format string](https://en.wikipedia.org/wiki/Uncontrolled_format_string) vulnerability by yourself. 
## Description
This library implement C printf-like formatting for C++ std::cout using vasprintf() from stdio.h.  
This library achieve the feature using relative short code compared to other methods like boost::format or std::experimental::putf, see [related thread on StackOverflow](https://stackoverflow.com/questions/15106102/how-to-use-c-stdostream-with-printf-like-formatting#15106194).
## Compiling the library manually
Download cxxprintf.cc, then in the terminal:  
```bash
g++ -c cxxprintf.cc
ar rcs cxxprintf.a cxxprintf.o
```
## Design
A new struct putf_r that contains char *s, will be used in << operator overloading  
putf() receive format string, pass it to vasprintf(), then the result is return by putf() as putf_r.s   
Overloading << operator with std::ostream and putf_r as argument, it will std::ostream<<putf_r.s, then free putf_r.s which is allocated by vasprintf()  
