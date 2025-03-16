#include "philo.h"

void    dream(t_philo *philo)
{
    print_info(philo, "is sleeping");
    precise_usleep(philo->table->time_to_sleep);
}

void    think(t_philo *philo)
{
    print_info(philo, "is thinking");
}

void    eat(t_philo *philo)
{
    if (philo->id == philo->table->philo_nbr)
    {
        mutex_manager(&philo->right_fork->fork, LOCK);
        print_info(philo, "Has taken a fork");
        mutex_manager(&philo->left_fork->fork, LOCK);
        print_info(philo, "Has taken a fork");
    }
    else
    {
        mutex_manager(&philo->left_fork->fork, LOCK);
        print_info(philo, "Has taken a fork");
        mutex_manager(&philo->right_fork->fork, LOCK);
        print_info(philo, "Has taken a fork");
    }
    philo->is_eating = 1;
    print_info(philo, "Is eating");
    philo->last_meal_time = get_msecs();
    philo->meals_counter++;
    precise_usleep(philo->table->time_to_eat);
    philo->is_eating = 0;
    mutex_manager(&philo->left_fork->fork, UNLOCK);
    print_info(philo, "Has put down a fork");
    mutex_manager(&philo->right_fork->fork, UNLOCK);
    print_info(philo, "Has put down a fork");
}

void    *philo_routine(void *philosopher)
{
    t_philo *philo = (t_philo *)philosopher;
   /* if (philo->id % 2 == 0)
        precise_usleep(1);*/
    while (42)
    {
        eat(philo);
        dream(philo);
        think(philo);
    }
    return (NULL);
}
