//
//  MyAsyncTaskManager.cpp
//  mygame
//
//  Created by bzx on 7/20/15.
//
//

#include "MyAsyncTaskManager.h"

USING_NS_MY;

AsyncTaskManager* AsyncTaskManager::getInstance()
{
    static auto ret = new(std::nothrow) AsyncTaskManager();
    return ret;
}

void AsyncTaskManager::addAsyncTask(AsyncTask* async_task, int thread_id)
{
    _threads.insert(std::pair<int, AsyncTask*>(thread_id, async_task));
}