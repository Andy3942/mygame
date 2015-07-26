//
//  lua_my_common.cpp
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#include "lua_my_common.h"
#include "MyCommonFunction.h"


int lua_register_my_common_function(lua_State* tolua_S)
{
    const luaL_reg global_functions [] = {
        {"lock", my::lock},
        {"unlock", my::unlock},
        {nullptr, nullptr}
    };
    luaL_register(tolua_S, "_G", global_functions);
    return 1;
}

int register_all_my_common(lua_State* tolua_S)
{
    lua_register_my_common_function(tolua_S);
    return 1;
}