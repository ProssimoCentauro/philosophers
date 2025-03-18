#include "philo.h"

static int	check_len(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\"')
	{
		i++;
		count++;
		if (count >= 11)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}


static void	check_usage(int ac, char **av)
{
    size_t  i;

    i = 0;
	if (!av[5] && ac != 5)
		exit_error(NULL, print_usage_error);
	else if (av[5] && ac != 6)
		exit_error(NULL, print_usage_error);
    if (!check_args(av))
        exit_error(NULL, print_usage_error);
    while (av[++i])
    {
        if (!check_len(av[i]))
            exit_error(NULL, print_usage_error);
    }
}

int	main(int ac, char **av)
{
	t_table	table;

	check_usage(ac, av);
	set_the_table(&table, av);
	init_table(&table);
	start_philos(&table);
	return (0);
}
