use_header=$(cat playground.cpp | grep -E '^#include "header.h"')
if [ "$use_header" ]; then
    cat header.h playground.cpp | sed '/^#include "header.h"/d' > code.cpp
else
    cat playground.cpp > code.cpp
fi
g++ -o code code.cpp -I./ac-library/ && echo  "./code" && ./code
