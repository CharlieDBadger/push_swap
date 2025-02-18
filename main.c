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


void free_array(char **matrix)
{
	int i = 0;

	if (!matrix)
		return;
	while (matrix[i])

	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void ft_lstprint(t_data *lst)
{
    int i = 0;

    while (lst)
    {
        ft_printf("Elemento #%i: %i\n", i, lst->content);
        lst = lst->next;
        i++;
    }
}

int	main(int argc, char **argv)
{
	char	**data;
	t_data	*data_set;
	int		split;
	
	split = 0;
	if (argc == 1)
	{
		ft_putchar('\n');
		return (1);
	}
	else if (argc == 2)
	{
		data = ft_split(argv[1], ' ');
		split = 1;
	}
	else
		data = argv;
	
	data_set = data_set_generator(data);
	if (!data_set)
	{
		ft_printf("Error: Invalid data or duplicates found.\n");
		return (1);
	}

	ft_lstprint(data_set);
	ft_lstcleardat(&data_set);
	if(split)
		free_array(data);
	
	return (0);
}

