# CxxPrintf
C++ printf for std::cout implemented using vasprintf  
  
## Usage
```C++
#include "cxxprintf.hh"
std::cout << putf(const char *format, ...); //Same as C printf(3)
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
