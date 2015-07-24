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

USING_NS_CC; 

NS_MY_BEGIN

class Map:public Ref
{
public:
    Map();
    virtual ~Map();

    static Map* create();
    Value at(const std::string& key);
    void insert(const std::string& key, Value object);
    size_t erase(const std::string& k);
private:
    std::unordered_map<std::string, Value> _data;
};

NS_MY_END

#endif /* defined(__mygame__MyMap__) */
