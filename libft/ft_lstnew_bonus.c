/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:31:57 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/28 17:16:38 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *begin;

	if (!(begin = (malloc(sizeof(t_list)))))
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
