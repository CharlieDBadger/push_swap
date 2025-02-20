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

static int	duplicates(t_stack *head)
{
	t_stack	*current;
	t_stack	*runner;

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

static int	is_sorted_ascending(t_stack *head)
{
	t_stack	*current;

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

t_stack	*stack_generator(char **raw_stack, int index)
{
	int		i;
	long	num;
	t_stack	*stack;
	t_stack	*new_node;

	stack = NULL;
	i = 0;
	if (!ft_isdigit(*raw_stack[i]))
		i = 1;
	while (raw_stack[i] != NULL)
	{
		if (!is_valid_number(raw_stack[i]))
			return (ft_lstcleardat(&stack), NULL);
		num = ft_atol(raw_stack[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_lstcleardat(&stack), NULL);
		new_node = ft_lstnewdat(index++, (int)num);
		if (!new_node)
			return (ft_lstcleardat(&stack), NULL);
		ft_lstadddat_back(&stack, new_node);
		i++;
	}
	if (duplicates(stack) || is_sorted_ascending(stack))
		return (ft_lstcleardat(&stack), NULL);
	return (stack);
}
