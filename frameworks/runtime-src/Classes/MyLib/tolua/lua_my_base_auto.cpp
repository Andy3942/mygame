#include "lua_my_base_auto.hpp"
#include "MyMap.h"
#include "MyVector.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "MyLuaBasicConversions.h"


int lua_my_base_Map_insert(lua_State* tolua_S)
{
    int argc = 0;
    my::Map* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Map",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Map*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Map_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        my::MyValue arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "my.Map:insert");

        ok &= luaval_to_myvalue(tolua_S, 3, &arg1, "my.Map:insert");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Map_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Map:insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Map_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Map_erase(lua_State* tolua_S)
{
    int argc = 0;
    my::Map* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Map",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Map*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Map_erase'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "my.Map:erase");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Map_erase'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->erase(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Map:erase",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Map_erase'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Map_at(lua_State* tolua_S)
{
    int argc = 0;
    my::Map* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Map",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Map*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Map_at'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "my.Map:at");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Map_at'", nullptr);
            return 0;
        }
        my::MyValue ret = cobj->at(arg0);
        myvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Map:at",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Map_at'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Map_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"my.Map",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Map_create'", nullptr);
            return 0;
        }
        my::Map* ret = my::Map::create();
        object_to_luaval<my::Map>(tolua_S, "my.Map",(my::Map*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "my.Map:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Map_create'.",&tolua_err);
#endif
    return 0;
}
int lua_my_base_Map_constructor(lua_State* tolua_S)
{
    int argc = 0;
    my::Map* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Map_constructor'", nullptr);
            return 0;
        }
        cobj = new my::Map();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"my.Map");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Map:Map",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Map_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_my_base_Map_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Map)");
    return 0;
}

int lua_register_my_base_Map(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"my.Map");
    tolua_cclass(tolua_S,"Map","my.Map","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Map");
        tolua_function(tolua_S,"new",lua_my_base_Map_constructor);
        tolua_function(tolua_S,"insert",lua_my_base_Map_insert);
        tolua_function(tolua_S,"erase",lua_my_base_Map_erase);
        tolua_function(tolua_S,"at",lua_my_base_Map_at);
        tolua_function(tolua_S,"create", lua_my_base_Map_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(my::Map).name();
    g_luaType[typeName] = "my.Map";
    g_typeCast["Map"] = "my.Map";
    return 1;
}

int lua_my_base_Vector_at(lua_State* tolua_S)
{
    int argc = 0;
    my::Vector* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Vector",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Vector*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Vector_at'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;

        ok &= luaval_to_ssize(tolua_S, 2, &arg0, "my.Vector:at");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Vector_at'", nullptr);
            return 0;
        }
        my::MyValue ret = cobj->at(arg0);
        myvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Vector:at",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Vector_at'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Vector_erase(lua_State* tolua_S)
{
    int argc = 0;
    my::Vector* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Vector",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Vector*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Vector_erase'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;

        ok &= luaval_to_ssize(tolua_S, 2, &arg0, "my.Vector:erase");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Vector_erase'", nullptr);
            return 0;
        }
        cobj->erase(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Vector:erase",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Vector_erase'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Vector_pushBack(lua_State* tolua_S)
{
    int argc = 0;
    my::Vector* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Vector",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Vector*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Vector_pushBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        my::MyValue arg0;

        ok &= luaval_to_myvalue(tolua_S, 2, &arg0, "my.Vector:pushBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Vector_pushBack'", nullptr);
            return 0;
        }
        cobj->pushBack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Vector:pushBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Vector_pushBack'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Vector_size(lua_State* tolua_S)
{
    int argc = 0;
    my::Vector* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"my.Vector",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (my::Vector*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_my_base_Vector_size'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Vector_size'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->size();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "my.Vector:size",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Vector_size'.",&tolua_err);
#endif

    return 0;
}
int lua_my_base_Vector_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"my.Vector",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_my_base_Vector_create'", nullptr);
            return 0;
        }
        my::Vector* ret = my::Vector::create();
        object_to_luaval<my::Vector>(tolua_S, "my.Vector",(my::Vector*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "my.Vector:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_my_base_Vector_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_my_base_Vector_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Vector)");
    return 0;
}

int lua_register_my_base_Vector(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"my.Vector");
    tolua_cclass(tolua_S,"Vector","my.Vector","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Vector");
        tolua_function(tolua_S,"at",lua_my_base_Vector_at);
        tolua_function(tolua_S,"erase",lua_my_base_Vector_erase);
        tolua_function(tolua_S,"pushBack",lua_my_base_Vector_pushBack);
        tolua_function(tolua_S,"size",lua_my_base_Vector_size);
        tolua_function(tolua_S,"create", lua_my_base_Vector_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(my::Vector).name();
    g_luaType[typeName] = "my.Vector";
    g_typeCast["Vector"] = "my.Vector";
    return 1;
}
TOLUA_API int register_all_my_base(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"my",0);
	tolua_beginmodule(tolua_S,"my");

	lua_register_my_base_Map(tolua_S);
	lua_register_my_base_Vector(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

