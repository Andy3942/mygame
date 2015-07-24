//
//  MyAsyncTaskManager.h
//  mygame
//
//  Created by bzx on 7/20/15.
//
//

#ifndef __mygame__MyAsyncTaskManager__
#define __mygame__MyAsyncTaskManager__

#include <stdio.h>
#include <thread>
#include <unordered_map>

#include "MyMacros.h"
#include "MyAsyncTask.h"


NS_MY_BEGIN

class AsyncTaskManager
{
public:
    static AsyncTaskManager* getInstance();
    void addAsyncTask(AsyncTask* async_task, int thread_id);
private:
    std::unordered_map<int, AsyncTask*> _threads;
};

NS_MY_END


#endif /* defined(__mygame__MyAsyncTaskManager__) */
