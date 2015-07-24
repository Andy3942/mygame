//
//  MyVector.cpp
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#include "MyVector.h"

my::Vector::~Vector()
{
}
    
my::Vector* my::Vector::create()
{
    auto ret = new(std::nothrow) Vector();
    return ret;
}

ssize_t my::Vector::size() const
{
    return  _data.size();
}

void my::Vector::pushBack(Value v)
{
    // CCASSERT(object != nullptr, "The object should not be nullptr");
    _data.push_back( v );
    // object->retain();
}

Value my::Vector::at(ssize_t index) const
{
    CCASSERT( index >= 0 && index < size(), "index out of range in getObjectAtIndex()");
    return _data[index];
}
