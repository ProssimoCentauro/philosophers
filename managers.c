#include "philo.h"

void    mutex_manager(pthread_mutex_t *mtx, t_codes code)
{
    int ret;

    if (code == INIT)
        ret = pthread_mutex_init(mtx, NULL);
    else if (code == DESTROY)
        ret = pthread_mutex_destroy(mtx);
    else if (code == LOCK)
        ret = pthread_mutex_lock(mtx);
    else if (code == UNLOCK)
        ret = pthread_mutex_unlock(mtx);
    if (ret != 0)
        exit_error("MUTEX ERROR!");
}

void    thread_manager(pthread_t *thread, void *(*f)(void *),
        void *arg, t_codes code)
{
    int ret;

    if (code == CREATE)
        ret = pthread_create(thread, NULL, f, arg);
    else if (code == DETACH)
        ret = pthread_detach(*thread);
    else if (code == JOIN)
        ret = pthread_join(*thread, NULL);
    if (ret != 0)
        exit_error("THREAD ERROR!");
}
