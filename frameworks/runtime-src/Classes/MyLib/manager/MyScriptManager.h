//
//  MyScriptManager.h
//  mygame
//
//  Created by bzx on 7/17/15.
//
//

#ifndef __mygame__MyScriptManager__
#define __mygame__MyScriptManager__

#include <stdio.h>
#include <CCValue.h>

#include "MyMacros.h"
#include "CCLuaStack.h"

USING_NS_CC;

NS_MY_BEGIN

class ScriptManager
{
public:
    static ScriptManager* getInstance();
    
    void asyncExecuteScriptFile(const char* filename, int thread_id);
private:
};

NS_MY_END

#endif /* defined(__mygame__MyScriptManager__) */
