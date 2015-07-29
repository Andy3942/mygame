//
//  MyVector.cpp
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#include "MyVector.h"

NS_MY_BEGIN

Vector::~Vector()
{
}
    
Vector* Vector::create()
{
    auto ret = new(std::nothrow) Vector();
    return ret;
}

ssize_t Vector::size() const
{
    return  _data.size();
}

void Vector::pushBack(Value v)
{
    _lock.lock();
    // CCASSERT(object != nullptr, "The object should not be nullptr");
    _data.push_back( v );
    // object->retain();
    _lock.unlock();
}

Value Vector::at(ssize_t index)
{
    _lock.lock();
    CCASSERT( index >= 0 && index < size(), "index out of range in getObjectAtIndex()");
    _lock.unlock();
    return _data[index];
}

void Vector::erase(ssize_t index)
{
    _lock.lock();
    _data.erase(_data.begin() + index);
    _lock.unlock();
}

NS_MY_END