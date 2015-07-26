//
//  MyDataManager.h
//  mygame
//
//  Created by bzx on 7/24/15.
//
//

#ifndef __mygame__MyDataManager__
#define __mygame__MyDataManager__

#include <stdio.h>

#include "cocos2d.h"

#include "MyMap.h"

NS_MY_BEGIN

class DataManager
{
public:
    static DataManager* getInstance();
    Map* getShareData();
private:
    Map* _share_data;
};

NS_MY_END

#endif /* defined(__mygame__MyDataManager__) */
