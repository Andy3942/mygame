//
//  MyMap.h
//  mygame
//
//  Created by bzx on 7/21/15.
//
//

#ifndef __mygame__MyMap__
#define __mygame__MyMap__

#include <stdio.h>
#include <unordered_map>

#include "cocos2d.h"
#include "MyMacros.h"
#include "MyValue.h"

NS_MY_BEGIN

class Map:public cocos2d::Ref
{
public:
    Map();
    virtual ~Map();

    static Map* create();
    MyValue at(const std::string& key);
    void insert(const std::string& key, MyValue object);
    size_t erase(const std::string& key);
private:
    std::unordered_map<std::string, MyValue> _data;
    std::mutex _lock;
};

NS_MY_END

#endif /* defined(__mygame__MyMap__) */
