//
//  MyValue.h
//  mygame
//
//  Created by bzx-mac on 7/24/15.
//
//

#ifndef __mygame__MyValue__
#define __mygame__MyValue__

#include <stdio.h>

#include "cocos2d.h"
#include "MyMacros.h"
#include "CCLuaValue.h"

NS_MY_BEGIN

class Map;
class Vector;
class Value;

typedef Value MyValue;

class Value
{
public:
    static const Value Null;

    Value();
    explicit Value(int v);
    explicit Value(float v);
    explicit Value(double v);
    explicit Value(const std::string& v);
    explicit Value(Map* v);
    explicit Value(Vector* v);
    
    int asInt() const;
    float asFloat() const;
    double asDouble() const;
    bool asBool() const;
    std::string asString() const;
    Map* asMap() const;
    Vector* asVector() const;

    enum class Type
    {
        NONE = 0,
        BYTE,
        INTEGER,
        LUA_FUNCTION,
        FLOAT,
        DOUBLE,
        BOOLEAN,
        STRING,
        VOID_P,
        MY_MAP,
        MY_VECTOR,
    };
    /** Gets the value type. */
    inline Type getType() const { return _type; }
    inline void setType(Type type){ _type = type;}
private:
    union
    {
        unsigned char byteVal;
        int intVal;
        float floatVal;
        double doubleVal;
        bool boolVal;
        std::string* strVal;
        Map* mapVal;
        Vector* vecVal;
    }_field;
    Type _type;
};
NS_MY_END

#endif /* defined(__mygame__MyValue__) */
