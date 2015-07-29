#include "base/ccConfig.h"
#ifndef __my_base_h__
#define __my_base_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_my_base(lua_State* tolua_S);













#endif // __my_base_h__
