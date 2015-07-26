//
//  MyMap.cpp
//  mygame
//
//  Created by bzx on 7/21/15.
//
//

#include "MyMap.h"

NS_MY_BEGIN

Map::Map()
{
}

Map::~Map()
{
}

Map* Map::create()
{
    auto ret = new(std::nothrow) Map();
    return ret;
}

Value Map::at(const std::string& key)
{
    _lock.lock();
    auto iter = _data.find(key);
    if (iter != _data.end())
    {
        _lock.unlock();
        return iter->second;
    }
    _lock.unlock();
    return (Value)Value::Null;
}

void Map::insert(const std::string& key, Value object)
{
    _lock.lock();
    //CCASSERT(object != nullptr, "Object is nullptr!");
    //erase(key);
    _data.insert(std::make_pair(key, object));
    //object->retain();
    _lock.unlock();

}

size_t Map::erase(const std::string& k)
{
    _lock.lock();
    auto iter = _data.find(k);
    if (iter != _data.end())
    {
        //iter->second->release();
        _data.erase(iter);
        _lock.unlock();
        return 1;
    }
    _lock.unlock();
    return 0;
}

NS_MY_END