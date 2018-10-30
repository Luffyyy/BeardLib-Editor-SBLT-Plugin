#include "myfuncs.h"
#include <string>

//Taken from BundleModder code
ullong swap_endianness(ullong uvalue)
{
	ullong swapped = 0x00000000000000FF & (uvalue >> 56) | 0x000000000000FF00 & (uvalue >> 40)
		| 0x0000000000FF0000 & (uvalue >> 24) | 0x00000000FF000000 & (uvalue >> 8)
		| 0x000000FF00000000 & (uvalue << 8) | 0x0000FF0000000000 & (uvalue << 24)
		| 0x00FF000000000000 & (uvalue << 40) | 0xFF00000000000000 & (uvalue << 56);
	return swapped;
}

ullong swap_endianness(lua_State * L)
{
	return ullong();
}

int lua_swap_endianness(lua_State *L) {
	ullong l = swap_endianness(strtoull(luaL_checkstring(L, 1), NULL, 16));

	char str[17];
	
	snprintf(str, 17, "%llX", l);
	
	if (str[15] == NULL)
		strcat(str, "0");

	lua_pushstring(L, strlwr(str));

	return 1;
}
