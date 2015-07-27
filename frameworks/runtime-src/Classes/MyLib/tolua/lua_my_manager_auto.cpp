#include "lua_my_manager_auto.hpp"
#include "MyDataManager.h"
#include "MyScriptManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "MyLuaBasicConversions.h"


int lua_my_manager_DataManager_getSharedData(lua_State* tolua_S)
{
    int argc = 0;
    my::DataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::DataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_manager_DataManager_getSharedData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_manager_DataManager_getSharedData'", nullptr);
            return 0;
        }
        my::Map* ret = cobj->getSharedData();
        object_to_luaval<my::Map>(tolua_S, "my.Map",(my::Map*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.DataManager:getSharedData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_manager_DataManager_getSharedData'.",&tolua_err);
#endif

    return 0;
}
int lua_my_manager_DataManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"my.DataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_manager_DataManager_getInstance'", nullptr);
            return 0;
        }
        my::DataManager* ret = my::DataManager::getInstance();
        object_to_luaval<my::DataManager>(tolua_S, "my.DataManager",(my::DataManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "my.DataManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_manager_DataManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_my_manager_DataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DataManager)");
    return 0;
}

int lua_register_my_manager_DataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"my.DataManager");
    tolua_cclass(tolua_S,"DataManager","my.DataManager","",nullptr);

    tolua_beginmodule(tolua_S,"DataManager");
        tolua_function(tolua_S,"getSharedData",lua_my_manager_DataManager_getSharedData);
        tolua_function(tolua_S,"getInstance", lua_my_manager_DataManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(my::DataManager).name();
    g_luaType[typeName] = "my.DataManager";
    g_typeCast["DataManager"] = "my.DataManager";
    return 1;
}

int lua_my_manager_ScriptManager_asyncExecuteScriptFile(lua_State* tolua_S)
{
    int argc = 0;
    my::ScriptManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.ScriptManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::ScriptManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_manager_ScriptManager_asyncExecuteScriptFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "my.ScriptManager:asyncExecuteScriptFile"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "my.ScriptManager:asyncExecuteScriptFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_manager_ScriptManager_asyncExecuteScriptFile'", nullptr);
            return 0;
        }
        cobj->asyncExecuteScriptFile(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.ScriptManager:asyncExecuteScriptFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_manager_ScriptManager_asyncExecuteScriptFile'.",&tolua_err);
#endif

    return 0;
}
int lua_my_manager_ScriptManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"my.ScriptManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_manager_ScriptManager_getInstance'", nullptr);
            return 0;
        }
        my::ScriptManager* ret = my::ScriptManager::getInstance();
        object_to_luaval<my::ScriptManager>(tolua_S, "my.ScriptManager",(my::ScriptManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "my.ScriptManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_manager_ScriptManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_my_manager_ScriptManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ScriptManager)");
    return 0;
}

int lua_register_my_manager_ScriptManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"my.ScriptManager");
    tolua_cclass(tolua_S,"ScriptManager","my.ScriptManager","",nullptr);

    tolua_beginmodule(tolua_S,"ScriptManager");
        tolua_function(tolua_S,"asyncExecuteScriptFile",lua_my_manager_ScriptManager_asyncExecuteScriptFile);
        tolua_function(tolua_S,"getInstance", lua_my_manager_ScriptManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(my::ScriptManager).name();
    g_luaType[typeName] = "my.ScriptManager";
    g_typeCast["ScriptManager"] = "my.ScriptManager";
    return 1;
}
TOLUA_API int register_all_my_manager(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"my",0);
	tolua_beginmodule(tolua_S,"my");

	lua_register_my_manager_ScriptManager(tolua_S);
	lua_register_my_manager_DataManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

