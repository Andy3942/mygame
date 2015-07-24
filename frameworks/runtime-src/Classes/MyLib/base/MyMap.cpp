//
//  MyMap.cpp
//  mygame
//
//  Created by bzx on 7/21/15.
//
//

#include "MyMap.h"

USING_NS_MY;

my::Map::Map()
{
}

my::Map::~Map()
{
}

my::Map* my::Map::create()
{
    auto ret = new(std::nothrow) Map();
    return ret;
}

Value my::Map::at(const std::string& key)
{
    auto iter = _data.find(key);
    if (iter != _data.end())
        return iter->second;
    return (Value)0;
}

void my::Map::insert(const std::string& key, Value object)
{
    //CCASSERT(object != nullptr, "Object is nullptr!");
    //erase(key);
    _data.insert(std::make_pair(key, object));
    //object->retain();
}

size_t my::Map::erase(const std::string& k)
    {
        auto iter = _data.find(k);
        if (iter != _data.end())
        {
            //iter->second->release();
            _data.erase(iter);
            return 1;
        }
        
        return 0;
    }