//
//  ScriptManager.h
//  mygame
//
//  Created by bzx on 7/17/15.
//
//

#ifndef __mygame__ScriptManager__
#define __mygame__ScriptManager__

#include <stdio.h>

class ScriptManager
{
public:
    static ScriptManager* getInstance();
    
    void asyncExecuteScriptFile(const char* filename);
};

#endif /* defined(__mygame__ScriptManager__) */
