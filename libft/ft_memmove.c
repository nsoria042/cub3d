/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:28:32 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:44:00 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;
	char	*i;
	char	*d;
	char	temp[len];

	a = 0;
	i = (char *)src;
	d = (char *)dst;
	if ((i == '\0' && d == '\0') || len >= (128 * 1024 * 1024))
		return (NULL);
	if (!len || i == d)
		return (d);
	while (a < len)
	{
		temp[a] = i[a];
		a++;
	}
	a = 0;
	while (a < len)
	{
		d[a] = temp[a];
		a++;
	}
	return (d);
}
