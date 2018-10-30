#pragma once

// Include SuperBLT
#include <superblt_flat.h>

// Add function declarations here.
typedef unsigned long long ullong;

ullong swap_endianness(ullong uvalue);
int lua_swap_endianness(lua_State *L);