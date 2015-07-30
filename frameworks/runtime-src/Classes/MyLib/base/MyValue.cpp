//
//  MyValue.cpp
//  mygame
//
//  Created by bzx-mac on 7/24/15.
//
//

#include "MyValue.h"
#include "MyMap.h"
#include "MyVector.h"

NS_MY_BEGIN

const Value Value::Null;

Value::Value()
:_type(Type::NONE)
{
}

Value::Value(int v)
:_type(Type::INTEGER)
{
    _field.intVal = v;
}

Value::Value(float v)
:_type(Type::FLOAT)
{
    _field.floatVal = v;
}

Value::Value(double v)
:_type(Value::Type::DOUBLE)
{
    _field.doubleVal = v;
}

Value::Value(const std::string& v)
: _type(Type::STRING)
{
    _field.strVal = new std::string();
    *_field.strVal = v;
}

Value::Value(void* v, const char* type_name)
:_type(Value::Type::VOID_P)
{
    _field.pVal = v;
    _type_name = type_name;
}

Value::Value(Map* v)
:_type(Value::Type::MY_MAP)
{
    _field.mapVal = v;
}

Value::Value(Vector* v)
:_type(Value::Type::MY_VECTOR)
{
    _field.vecVal = v;
}

int Value::asInt() const
{
    return _field.intVal;
}

float Value::asFloat() const
{
    return  _field.floatVal;
}

double Value::asDouble() const
{
    return _field.doubleVal;
}

bool Value::asBool() const
{
    return _field.boolVal;
}

std::string Value::asString() const
{
    return *_field.strVal;
}

void* Value::asVoidP() const
{
    return _field.pVal;
}

Map* Value::asMap() const
{
    return _field.mapVal;
}

Vector* Value::asVector() const
{
    return _field.vecVal;
}

const char* Value::getTypeName() const
{
    return _type_name.c_str();
}

NS_MY_END