#include "philo.h"

static void	check_usage(int ac, char **av)
{
	if (!av[5] && ac != 5)
		exit_error(USAGE_ERROR);
	else if (av[5] && ac != 6)
		exit_error(USAGE_ERROR);
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
