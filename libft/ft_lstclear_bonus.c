/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:49:02 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/23 12:49:25 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*value;
	t_list	*temp;

	value = *lst;
	if (!value)
		return ;
	while (value)
	{
		if (value->next)
			temp = value->next;
		else
			temp = NULL;
		del(value->content);
		free(value);
		value = temp;
	}
	*lst = NULL;
}
