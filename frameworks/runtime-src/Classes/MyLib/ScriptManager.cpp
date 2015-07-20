//
//  ScriptManager.cpp
//  mygame
//
//  Created by bzx on 7/17/15.
//
//

#include "ScriptManager.h"

#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
#include <unistd.h>

USING_NS_CC;

ScriptManager* ScriptManager::getInstance()
{
    static auto ret = new ScriptManager();
    return ret;
}

void ScriptManager::asyncExecuteScriptFile(const char *filename)
{
    LuaStack* L = LuaStack::createClean();
    L->executeScriptFile(filename);
}