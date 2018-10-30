// Include SuperBLT
#include <superblt_flat.h>

#include "myfuncs.h"

// See superblt_flat.h for a description of what these functions do

void Plugin_Init() {
	// Put your one-time initialization code here
}

void Plugin_Update() {
	// Put your per-frame update code here
}

void Plugin_Setup_Lua(lua_State *L) {
	// Put your Lua setup code here

	// And read this until you understand what's happening: https://www.lua.org/pil/24.html
	// For a comprehensive reference of what all the functions do, please
	// read the Lua 5.1 manual:	http://www.lua.org/manual/5.1/manual.html
	// (note that on Windows, only some of the functions in the manual are avaiable).

	// Create a Lua table
	lua_newtable(L);

	// Add a C function to it
	lua_pushcfunction(L, lua_swap_endianness);
	lua_setfield(L, -2, "swap_endianness");

	// Set the table as a global
	lua_setglobal(L, "BLEP");
}
