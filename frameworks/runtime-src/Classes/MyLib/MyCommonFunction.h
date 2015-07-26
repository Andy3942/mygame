//
//  MyCommonFunction.h
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#ifndef __mygame__MyCommonFunction__
#define __mygame__MyCommonFunction__

#include <stdio.h>
#include "MyMacros.h"
#include "MyCommonField.h"

NS_MY_BEGIN

int lock(lua_State * L);
int unlock(lua_State * L);

NS_MY_END

#endif /* defined(__mygame__MyCommonFunction__) */
