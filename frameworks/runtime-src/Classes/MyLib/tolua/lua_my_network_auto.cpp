#include "lua_my_network_auto.hpp"
#include "MySocket.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "MyLuaBasicConversions.h"


int lua_my_network_Socket_getError(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_getError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_getError'", nullptr);
            return 0;
        }
        int ret = cobj->getError();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:getError",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_getError'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_receive(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_receive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_receive'", nullptr);
            return 0;
        }
        std::string ret = cobj->receive();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "my.Socket:receive");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_receive'", nullptr);
            return 0;
        }
        std::string ret = cobj->receive(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:receive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_receive'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_getStrError(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_getStrError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "my.Socket:getStrError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_getStrError'", nullptr);
            return 0;
        }
        const char* ret = cobj->getStrError(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:getStrError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_getStrError'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_send(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_send'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "my.Socket:send"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_send'", nullptr);
            return 0;
        }
        bool ret = cobj->send(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:send",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_send'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_init(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        my::SocketType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "my.Socket:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_init'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_connet(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_connet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        unsigned short arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "my.Socket:connet"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "my.Socket:connet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_connet'", nullptr);
            return 0;
        }
        bool ret = cobj->connet(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:connet",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_connet'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_close(lua_State* tolua_S)
{
    int argc = 0;
    my::Socket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Socket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_network_Socket_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_close'", nullptr);
            return 0;
        }
        int ret = cobj->close();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Socket:close",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_close'.",&tolua_err);
#endif

    return 0;
}
int lua_my_network_Socket_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"my.Socket",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_create'", nullptr);
            return 0;
        }
        my::Socket* ret = my::Socket::create();
        object_to_luaval<my::Socket>(tolua_S, "my.Socket",(my::Socket*)ret);
        return 1;
    }
    if (argc == 1)
    {
        my::SocketType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "my.Socket:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_network_Socket_create'", nullptr);
            return 0;
        }
        my::Socket* ret = my::Socket::create(arg0);
        object_to_luaval<my::Socket>(tolua_S, "my.Socket",(my::Socket*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "my.Socket:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_network_Socket_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_my_network_Socket_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Socket)");
    return 0;
}

int lua_register_my_network_Socket(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"my.Socket");
    tolua_cclass(tolua_S,"Socket","my.Socket","",nullptr);

    tolua_beginmodule(tolua_S,"Socket");
        tolua_function(tolua_S,"getError",lua_my_network_Socket_getError);
        tolua_function(tolua_S,"receive",lua_my_network_Socket_receive);
        tolua_function(tolua_S,"getStrError",lua_my_network_Socket_getStrError);
        tolua_function(tolua_S,"send",lua_my_network_Socket_send);
        tolua_function(tolua_S,"init",lua_my_network_Socket_init);
        tolua_function(tolua_S,"connet",lua_my_network_Socket_connet);
        tolua_function(tolua_S,"close",lua_my_network_Socket_close);
        tolua_function(tolua_S,"create", lua_my_network_Socket_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(my::Socket).name();
    g_luaType[typeName] = "my.Socket";
    g_typeCast["Socket"] = "my.Socket";
    return 1;
}
TOLUA_API int register_all_my_network(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"my",0);
	tolua_beginmodule(tolua_S,"my");

	lua_register_my_network_Socket(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

