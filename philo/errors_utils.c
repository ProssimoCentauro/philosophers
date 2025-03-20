/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:01 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:58:02 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_usage_error(void)
{
	printf("------------------------------\n");
	printf("|        \033[1;4;33mUSAGE MANUAL\033[0m        |\n");
	printf("|----------------------------|\n");
	printf("|  \033[1;32mto use the software type: \033[0m|\n");
	printf("|    ./philo <arguments>     |\n");
	printf("|                            |\n");
	printf("|        \033[1;32mARGUMENTS:\033[0m          |\n");
	printf("|     number_of_philos       |\n");
	printf("|       time_to_die          |\n");
	printf("|       time_to_eat          |\n");
	printf("|      time_to_sleep         |\n");
	printf("|   num_of_meals (optional)  |\n");
	printf("|                            |\n");
	printf("|                            |\n");
	printf("|      \033[1;32mUSAGE EXAMPLES:\033[0m       |\n");
	printf("| ./philo 5 800 200 200 10   |\n");
	printf("|----------------------------|\n");
}

int	exit_error(char *str, void (*f)(void), int code, int print)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		write(2, str, i);
	}
	if (f)
	{
		f();
	}
	if (print == 1)
		printf("\nERROR CODE: %d\n", code);
	return (code);
}
