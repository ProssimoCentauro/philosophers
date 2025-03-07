#include "philo.h"

/*
 * ./philo number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 * */

//no negatives!!!
int	check_args(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		if (!check_len(args[i]))
			return (0);
		j = 0;
		while (args[i][j] == ' ' || args[i][j] == '\t')
			j++;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			if (args[i][j] == '-')
				return (0);
			j++;
		}
		if (args[i][j] <= '0' && args[i][j] >= '9')
			return (0);
		while (args[i][j] >= '0' && args[i][j] <= '9' && args[i][j] != '\"')
			j++;
		if (args[i][j] != '\0')
			return (0);
		i++;
	}
	if (!args[0])
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	long	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sing = -sign;
		str++;
	}
	while (*str)
	{
		num *= 10;
		num += (*str - '0');
	}
	return (num * sign);
}

void	set_the_table(t_table	*table, char **args)
{
	if (!check_args(args))
		exit_error("USAGE_ERROR");

	table->philo_nbr = ft_atol(args[1]);
	table->time_to_die = ft_atol(args[2]) * 10000;
	table->time_to_eat = ft_atol(args[3]) * 10000;
	table->time_to_sleep = ft_atol(args[4]) * 10000;
	table->limit_meals = ft_atol(args[5]);
	
    if (table->time_to_die < 60000
            || table->time_to_eat < 60000
            || table->time_to_sleep < 60000)
        exit_error(USAGE_ERROR);
    //table->start_sim = 1;
	//table->end_sim = 0;
	//table->forks = (t_fork *)malloc(sizeof(t_fork) * ft_atol(args[1]));
	//table->philos = (t_philo *)malloc(sizeof(t_philo) * ft_atol(args[1]));
}
