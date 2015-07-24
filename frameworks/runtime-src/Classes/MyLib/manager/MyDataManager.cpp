//
//  MyDataManager.cpp
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#include "MyDataManager.h"
#include "MyMacros.h"

USING_NS_MY;

DataManager* DataManager::getInstance()
{
    static auto ret = new(std::nothrow) DataManager();
    return ret;
}

my::Map* DataManager::getShareData()
{
    static auto share_data = Map::create();
    if(!_share_data)
    {
        _share_data = share_data;
    }
    return _share_data;
}