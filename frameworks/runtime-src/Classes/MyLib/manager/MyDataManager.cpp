//
//  MyDataManager.cpp
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#include "MyDataManager.h"

NS_MY_BEGIN

DataManager* DataManager::getInstance()
{
    static auto ret = new(std::nothrow) DataManager();
    return ret;
}

my::Map* DataManager::getShareData()
{
    static auto share_data = my::Map::create();
    if(!_share_data)
    {
        _share_data = share_data;
    }
    return _share_data;
}

NS_MY_END