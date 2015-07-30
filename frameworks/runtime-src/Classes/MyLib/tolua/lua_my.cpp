//
//  lua_my.cpp
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#include "lua_my.h"
#include "lua_my_base_auto.hpp"
#include "lua_my_manager_auto.hpp"
#include "lua_my_network_auto.hpp"
#include "lua_my_common.h"

int register_all_my(lua_State* tolua_S)
{
    // auto
    register_all_my_base(tolua_S);
    register_all_my_manager(tolua_S);
    register_all_my_network(tolua_S);
    // manual
    register_all_my_common(tolua_S);
    return 1;
}