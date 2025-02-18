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

t_data	*ft_lstnewdat(int *content)
{
	t_data	*new_node;

	new_node = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadddat_back(t_data **lst, t_data *new)
{
	t_data	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstcleardat(t_data **lst, void (*del)(void*))
{
	t_data	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			del(temp->content);
			free(temp);
		}
	}
}
