/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:52:04 by cbolanos          #+#    #+#             */
/*   Updated: 2025/02/15 20:52:08 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**data;
	t_data	*data_set;

	if (argc == 1)
	{
		ft_putchar('\n');
		return (1);
	}
	else if (argc == 2)
	{
		data = ft_split(argv[1], ' ');
		data_set = data_set_generator(data);
		free_array_reverse(data);
	}
	else
		data_set = data_set_generator(argv);
	if (!data_set)
	{
		ft_printf("Error: Invalid data.\n");
		return (1);
	}
	ft_lstprint(data_set);
	ft_lstcleardat(&data_set);
	return (0);
}
