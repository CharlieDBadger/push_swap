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

int static	is_valid_number(char *s)
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

int static	check_int_range(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int static	duplicates(t_list *head)
{
	t_list	*current;
	t_list	*runner;

	current = head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

t_list	*data_set_generator(char **raw_data)
{
	int		i;
	long	num;
	t_list	*data_set;
	t_list	*new_node;

	data_set = NULL;
	i = 1;
	while (raw_data[i] != NULL)
	{
		if (!is_valid_number(raw_data[i]))
			return (NULL);
		num = ft_atol(raw_data[i]);
		if (!check_int_range(num))
			return (NULL);
		new_node = ft_lstnew((void *)num);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&data_set, new_node);
		i++;
	}
	if (duplicates(data_set))
		return (NULL);
	return (data_set);
}
