cat header.h playground.cpp > code.cpp
sed '/#include "header.h"/d' code.cpp > /dev/null
g++ -o code code.cpp && echo "./code" && ./code
