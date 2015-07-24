//
//  MyVector.h
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#ifndef __mygame__MyVector__
#define __mygame__MyVector__

#include <stdio.h>

#include <Vector>

#include "cocos2d.h"
#include "MyMacros.h"

USING_NS_CC;

NS_MY_BEGIN

class Vector:public Ref
{
public:
    virtual ~Vector();
    
    static Vector* create();
     ssize_t size() const;
    void pushBack(Value v);
    Value at(ssize_t index) const;
private:
    std::vector<Value> _data;
};

NS_MY_END
#endif /* defined(__mygame__MyVector__) */
