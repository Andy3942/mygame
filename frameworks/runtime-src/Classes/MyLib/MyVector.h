//
//  MyVector.h
//  mygame
//
//  Created by bzx on 7/21/15.
//
//

#ifndef __mygame__MyVector__
#define __mygame__MyVector__

#include <stdio.h>
#include <Vector>

#include "MyMacros.h"

NS_MY_BEGIN

template<class V>
class Vector:public Ref
{
public:
    virtual ~Vector<V>()
    {
    }
    
    static Vector<V>* create()
    {
        auto ret = new(std::nothrow) Vector<V>();
        return ret;
    }
    
     ssize_t size() const
    {
        return  _data.size();
    }
    
    void pushBack(V object)
    {
        // CCASSERT(object != nullptr, "The object should not be nullptr");
        _data.push_back( object );
        // object->retain();
    }
    
    V at(ssize_t index) const
    {
        CCASSERT( index >= 0 && index < size(), "index out of range in getObjectAtIndex()");
        return _data[index];
    }
    
private:
    std::vector<V> _data;
};

NS_MY_END

#endif /* defined(__mygame__MyVector__) */
