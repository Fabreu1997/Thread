#include "Thread.h"

pthread_mutex_t Thread::_mutex = NULL;

Thread::Thread()
{

}

Thread::~Thread()
{

}

void Thread::run()
{

}

void Thread::start()
{
    int status = pthread_attr_init(&_tAttribute);
    if(status != 0)
    {
        printError("Falha ao iniciar Atributo da Thread. . .");
    }

    status = pthread_create(&_threadID, &_tAttribute, Thread::runThread, (void*)this);
    if(status != 0)
    {
        printError("Falha ao Iniciar a Thread. . .");
    }

    status = pthread_attr_destroy(&_tAttribute);
    if(status != 0)
    {
        printError("Falha ao destroir Atributo da Thread. . .");
    }
}

void Thread::join()
{
    int status = pthread_join(_threadID, NULL);
    if(status != 0)
    {
        printError("Comando Join Falhou. . .");
    }
}

void* Thread::runThread(void* pThread)
{
    Thread* sThread = static_cast<Thread*>(pThread);
    if(NULL == sThread)
    {
        cout << "Thread falhou!!!" << endl;
    }
    else
    {
        sThread->run();
    }
    return(sThread);
}

void Thread::yield()
{
    sched_yield();
}

void Thread::lock()
{
    if(NULL == Thread::_mutex)
    {
        pthread_mutex_init(&Thread::_mutex, NULL);
    }
    pthread_mutex_lock(&Thread::_mutex);
}

void Thread::unlock()
{
    if(NULL != Thread::_mutex)
    {
        pthread_mutex_unlock(&Thread::_mutex);
    }
}

void Thread::printError(const string msg)
{
    lock(); //para a mensagem
    cout << "Error: " << msg << endl;
    unlock();
}
