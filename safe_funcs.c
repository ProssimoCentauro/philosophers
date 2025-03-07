#include "philo.h"

void    *safe_malloc(syze_t bytes)
{
    void    *res;

    res = malloc(bytes);
    if (!res)
        exit_error("MALLOC ERROR!");
    return (res);
}
