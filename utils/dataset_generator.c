/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataset_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:45:04 by cbolanos          #+#    #+#             */
/*   Updated: 2025/02/14 19:45:06 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	duplicates(t_data *head)
{
	t_data	*current;
	t_data	*runner;

	current = head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

static int	is_sorted_ascending(t_data *head)
{
	t_data	*current;

	if (!head)
		return (1);
	current = head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1); 
}

t_data	*data_set_generator(char **raw_data)
{
	int		i;
	long	num;
	t_data	*data_set;
	t_data	*new_node;

	data_set = NULL;
	i = 0;
	if (!ft_isdigit(*raw_data[i]))
		i = 1;
	while (raw_data[i] != NULL)
	{
		if (!is_valid_number(raw_data[i]))
			return (ft_lstcleardat(&data_set), NULL);
		num = ft_atol(raw_data[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_lstcleardat(&data_set), NULL);
		new_node = ft_lstnewdat(i, (int)num);
		if (!new_node)
			return (ft_lstcleardat(&data_set), NULL);
		ft_lstadddat_back(&data_set, new_node);
		i++;
	}
	if (duplicates(data_set) || is_sorted_ascending(data_set))
		return (ft_lstcleardat(&data_set), NULL);
	return (data_set);
}
