/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:52:17 by cbolanos          #+#    #+#             */
/*   Updated: 2025/02/15 20:52:19 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}			t_stack;

//push_swap
t_stack	*stack_generator(char **raw_stack,int index);

//swap
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);

//rotate
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);

//reverse rotate
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);

//push
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

// lst
t_stack	*ft_lstnewdat(int index, int value);
void	ft_lstadddat_back(t_stack **lst, t_stack *new);
void	ft_lstcleardat(t_stack **lst);
void	ft_lstprint(t_stack *lst);

//array
void	free_array(char **matrix);
void	print_array(char **array);
void	free_array_reverse(char **array);
int		count_array_elements(char **array);

#endif
