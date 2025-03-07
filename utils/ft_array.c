/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:52:52 by cbolanos          #+#    #+#             */
/*   Updated: 2025/02/15 20:52:56 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	count_array_elements(char **array)
{
	int	count;

	if (!array)
		return (0);
	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	free_array(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_array_reverse(char **array)
{
	int	i;

	if (!array)
		return ;
	i = count_array_elements(array);
	while (--i >= 0)
		free(array[i]);
	free(array);
}

void	print_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_printf("Elemento [%d]: %s\n", i, array[i]);
		i++;
	}
}
