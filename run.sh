cat header.h playground.cpp | sed '/#include "header.h"/d' > code.cpp
g++ -o code code.cpp && echo -I./ac-library/ "./code" && ./code
