//
//  MyAsyncTask.cpp
//  mygame
//
//  Created by bzx on 7/20/15.
//
//

#include "MyAsyncTask.h"

NS_MY_BEGIN

AsyncTask::AsyncTask()
:_stop(false)
{
    _thread = std::thread(
        [this]
        {
            while (!_stop)
            {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(_queueMutex);
                    if(_tasks.empty())
                    {
                        printf("线程等待\n");
                        _condition.wait(lock);
                        printf("线程被唤醒\n");
                    }
                    task = std::move(_tasks.front());
                    _tasks.pop();
                }
                task();
            }
        }
    );
}

AsyncTask::~AsyncTask()
{
    _stop = true;
    _thread.join();
}

NS_MY_END