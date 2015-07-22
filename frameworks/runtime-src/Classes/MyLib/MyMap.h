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


NS_MY_BEGIN

template<class K, class V>
class Map
{
public:
    static Map<K, V>* create()
    {
        auto ret = new(std::nothrow) Map<K, V>();
        return ret;
    }
    
    V at(const K& key)
    {
        auto iter = _data.find(key);
        if (iter != _data.end())
            return iter->second;
        return (V)0;
    }
    
    void insert(const K& key, V object)
    {
        //CCASSERT(object != nullptr, "Object is nullptr!");
        //erase(key);
        _data.insert(std::make_pair(key, object));
        //object->retain();
    }

    size_t erase(const K& k)
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

private:
    std::unordered_map<K, V> _data;
};

NS_MY_END

#endif /* defined(__mygame__MyMap__) */
