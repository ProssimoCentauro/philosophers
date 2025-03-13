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

	// args checker
	check_usage(ac, av);
	// parse args
	set_the_table(&table, av);
	// data init
	init_table(&table);
	// dinner_start
	// start_sim(&table);
	// clean
	//	printf("%lu", get_timestamp());
	start_philos(&table);
	//printf("%d\n", *table.philos[1].id);
	return (0);
}
