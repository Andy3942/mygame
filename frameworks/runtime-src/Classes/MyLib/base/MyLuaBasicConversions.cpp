//
//  MyLuaBasicConversions.cpp
//  mygame
//
//  Created by bzx-mac on 7/25/15.
//
//

#include "MyLuaBasicConversions.h"
#include "LuaBasicConversions.h"
#include "MyMap.h"
#include "MyVector.h"


void myvalue_to_luaval(lua_State* L,const my::Value& inValue)
{
    const my::Value& obj = inValue;
    switch (obj.getType())
    {   
        case my::Value::Type::NONE:
            lua_pushnil(L);
            break;
        case my::Value::Type::BOOLEAN:
            lua_pushboolean(L, obj.asBool());
            break;
        case my::Value::Type::FLOAT:
        case my::Value::Type::DOUBLE:
            lua_pushnumber(L, obj.asDouble());
            break;
        case my::Value::Type::INTEGER:
            lua_pushinteger(L, obj.asInt());
            break;
        case my::Value::Type::LUA_FUNCTION:
            toluafix_get_function_by_refid(L, obj.asInt());
            break;
        case my::Value::Type::STRING:
            lua_pushstring(L, obj.asString().c_str());
            break;
        case my::Value::Type::VOID_P:
            object_to_luaval(L, obj.getTypeName(), obj.asVoidP());
            break;
        case my::Value::Type::MY_VECTOR:
            object_to_luaval<my::Vector>(L, "my.Vector", obj.asVector());
            break;
        case my::Value::Type::MY_MAP:
            object_to_luaval<my::Map>(L, "my.Map", obj.asMap());
            break;
        default:
            break;
    }
}

bool luaval_to_myvalue(lua_State* L, int lo, my::Value* ret, const char* funcName)
{
    if ( nullptr == L || nullptr == ret)
        return false;

    bool ok = true;

    tolua_Error tolua_err;

    if ((lua_type(L, lo) == LUA_TSTRING)  && tolua_isstring(L, lo, 0, &tolua_err))
    {
        std::string stringValue = "";
        if (luaval_to_std_string(L, lo, &stringValue))
        {
            *ret = my::Value(stringValue);
        }
    }
    else if ((lua_type(L, lo) == LUA_TBOOLEAN) && tolua_isboolean(L, lo, 0, &tolua_err))
    {
        bool boolVal = false;
        if (luaval_to_boolean(L, lo, &boolVal))
        {
            *ret = my::Value(boolVal);
        }
    }
    else if ((lua_type(L, lo) == LUA_TNUMBER) && tolua_isnumber(L, lo, 0, &tolua_err))
    {
        *ret = my::Value(tolua_tonumber(L, lo, 0));
    }
    else if ((lua_type(L, lo) == LUA_TFUNCTION) && toluafix_isfunction(L, lo,"LUA_FUNCTION",0,&tolua_err))
    {
        LUA_FUNCTION handler = toluafix_ref_function(L,lo,0);
        *ret = my::Value(handler);
        ret->setType(my::Value::Type::LUA_FUNCTION);
    }else if ((lua_type(L, lo) == LUA_TUSERDATA))
    {
        if(tolua_isusertype(L,lo,"my.Map",0, &tolua_err))
        {
            my::Map* mapVal = (my::Map*)tolua_touserdata(L, lo, 0);
            *ret = my::Value(mapVal);
        }else if(tolua_isusertype(L, lo, "my.Vector", 0, &tolua_err))
        {
            my::Vector* vecVal = (my::Vector*)tolua_touserdata(L, lo, 0);
            *ret = my::Value(vecVal);
        }else
        {
            void* pVal = tolua_touserdata(L, lo, 0);
            *ret = my::Value(pVal);
        }
    }

    return ok;
}
