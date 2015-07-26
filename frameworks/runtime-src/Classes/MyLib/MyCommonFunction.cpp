//
//  MyCommonFunction.cpp
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#include "MyCommonFunction.h"

NS_MY_BEGIN

int lock(lua_State * L)
{
    sg_lock.lock();
    return 1;
}
int unlock(lua_State * L)
{
    sg_lock.unlock();
    return 1;
}

NS_MY_END