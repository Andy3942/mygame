//
//  MyLuaBasicConversions.h
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#ifndef __mygame__MyLuaBasicConversions__
#define __mygame__MyLuaBasicConversions__

extern "C" {
#include "lua.h"
#include "tolua++.h"
}
#include "tolua_fix.h"

#include <stdio.h>
#include "MyValue.h"
#include "MyMacros.h"

void myvalue_to_luaval(lua_State* L,const my::Value& inValue);

extern bool luaval_to_myvalue(lua_State* L, int lo, my::Value* ret, const char* funcName = "");


#endif /* defined(__mygame__MyLuaBasicConversions__) */
