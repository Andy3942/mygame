//
//  MyScriptManager.cpp
//  mygame
//
//  Created by bzx on 7/17/15.
//
//

#include "MyScriptManager.h"

#include <unistd.h>

#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"

#include "MyAsyncTaskManager.h"

#include "lua_my.h"

NS_MY_BEGIN

ScriptManager* ScriptManager::getInstance()
{
    static auto ret = new(std::nothrow) ScriptManager();
    return ret;
}

void ScriptManager::asyncExecuteScriptFile(const char *filename, int thread_id)
{
    AsyncTask* async_task = new(std::nothrow) AsyncTask();
    auto L = LuaStack::createWithLight();
    register_all_my(L->getLuaState());
    L->retain();
    std::string filename_str = filename;
    async_task->addTask([L, filename_str]()
    {
        L->executeScriptFile(filename_str.c_str());
        L->release();
    });
    AsyncTaskManager::getInstance()->addAsyncTask(async_task, thread_id);
}

NS_MY_END