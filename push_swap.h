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

typedef struct s_data
{
	int				content;
	struct s_data	*next;
}			t_data;

t_data	*data_set_generator(char **raw_data);
t_data	*data_set_generator_split(char **raw_data);

// lst
t_data	*ft_lstnewdat(int content);
void	ft_lstadddat_back(t_data **lst, t_data *new);
void	ft_lstcleardat(t_data **lst);
void	ft_lstprint(t_data *lst);

//array
void	free_array(char **matrix);
void	print_array(char **array);
void	free_array_reverse(char **array);
int		count_array_elements(char **array);
#endif
