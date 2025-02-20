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

t_stack	*split_lst_in_two(t_stack *stack)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*new_set;

	if (!stack || !stack->next)
		return (NULL);
	slow = stack;
	fast = stack;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	new_set = slow->next;
	slow->next = NULL;

	return (new_set);
}


int	main(int argc, char **argv)
{
	char	**data;
	t_stack	*stack;
	t_stack	*stack2;

	if (argc == 1)
	{
		ft_putchar('\n');
		return (1);
	}
	else if (argc == 2)
	{
		data = ft_split(argv[1], ' ');
		stack = stack_generator(data, 1);
		free_array_reverse(data);
	}
	else
		stack = stack_generator(argv, 1);
	if (!stack)
	{
		ft_printf("Error: Invalid data.\n");
		return (1);
	}
	stack2 = split_lst_in_two(stack);
	
	reverse_rotate_r(&stack, &stack2);
	
	ft_printf("Primer mitad.\n");
	ft_lstprint(stack);
	ft_printf("Segunda mitad.\n");
	ft_lstprint(stack2);
	
	
	ft_lstcleardat(&stack);
	ft_lstcleardat(&stack2);
	return (0);
}
