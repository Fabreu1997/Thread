#ifndef INCLUDED_THREAD_H
#define INCLUDED_THREAD_H

#include <pthread.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Thread
{
private:

    pthread_t _threadID;
    static pthread_mutex_t _mutex;
    pthread_attr_t _tAttribute;

private:

    static void* runThread(void* pThread);
    virtual void run();
    void printError(const string msg);

public:

    Thread();
    virtual ~Thread();

    void start();
    void join();
    void yield();
    void lock();
    void unlock();
};

/* mutex estático atributo da thread, pode conter
// informações sobre o funcionamento da thread;
*/

#endif // INCLUDED_THREAD_H
