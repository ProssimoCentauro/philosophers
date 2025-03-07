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
