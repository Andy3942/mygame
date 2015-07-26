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
#include "MyValue.h"

NS_MY_BEGIN

class Vector:public cocos2d::Ref
{
public:
    virtual ~Vector();
    
    static Vector* create();
     ssize_t size() const;
    void pushBack(MyValue v);
    MyValue at(ssize_t index);
private:
    std::vector<MyValue> _data;
    std::mutex _lock;
};

NS_MY_END
#endif /* defined(__mygame__MyVector__) */
