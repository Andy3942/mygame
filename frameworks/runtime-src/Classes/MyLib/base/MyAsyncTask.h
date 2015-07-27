//
//  MyAsyncTask.h
//  mygame
//
//  Created by bzx on 7/20/15.
//
//

#ifndef __mygame__MyAsyncTask__
#define __mygame__MyAsyncTask__

#include <stdio.h>
#include <thread>
#include <queue>

#include "MyMacros.h"
#include "cocos2d.h"

USING_NS_CC;

NS_MY_BEGIN

class AsyncTask
{
public:
    AsyncTask();
    ~AsyncTask();
    
    template<class F>
    inline void addTask(F&& f)
    {   
        auto task = f;
        {
            std::unique_lock<std::mutex> lock(_queueMutex);
            _tasks.emplace([task](){ task(); });
        }
        printf("唤醒线程\n");
        _condition.notify_one();
    }
private:
    bool _stop;
    std::thread _thread;
    std::mutex _queueMutex;
    std::condition_variable _condition;
    std::queue< std::function<void()> > _tasks;
};

NS_MY_END


#endif /* defined(__mygame__MyAsyncTask__) */
