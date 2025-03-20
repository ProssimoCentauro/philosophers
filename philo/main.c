/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:10 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:58:11 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_usage(int ac, char **av)
{
	size_t	i;

	i = 0;
	if (!av[5] && ac != 5)
		return (exit_error(NULL, print_usage_error, 1, 0));
	else if (av[5] && ac != 6)
		return (exit_error(NULL, print_usage_error, 1, 0));
	if (!check_args(av))
		return (exit_error(NULL, print_usage_error, 1, 0));
	while (av[++i])
	{
		if (!check_len(av[i]))
			return (exit_error(NULL, print_usage_error, 1, 0));
	}
    return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (check_usage(ac, av))
        return (EXIT_FAILURE);
	set_the_table(&table, av);
	if (init_table(&table))
        return (EXIT_FAILURE);
	start_philos(&table);
	return (EXIT_SUCCESS);
}
