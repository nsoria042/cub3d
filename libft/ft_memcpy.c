/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:23:45 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:41:47 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;
	char	*i;
	char	*d;

	a = 0;
	i = (char *)src;
	d = (char *)dst;
	if (i == '\0' && d == '\0')
		return (NULL);
	if (!n || i == d)
		return (d);
	while (a < n)
	{
		d[a] = i[a];
		a++;
	}
	return (d);
}
