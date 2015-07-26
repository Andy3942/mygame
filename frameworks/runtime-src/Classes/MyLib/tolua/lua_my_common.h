//
//  lua_my_common.h
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//


#include "base/ccConfig.h"
#ifndef __mygame__lua_my_common__
#define __mygame__lua_my_common__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_my_common(lua_State* tolua_S);


#endif /* defined(__mygame__lua_my_common__) */
