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
#include <vector>
#include <string>

#include "MyMacros.h"


NS_MY_BEGIN

class Map
{
public:
private:
    std::unordered_map<std::string, double> _downloadedSize;
};

NS_MY_END

#endif /* defined(__mygame__MyMap__) */
