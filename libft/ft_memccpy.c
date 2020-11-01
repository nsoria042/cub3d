/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:31:49 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:30:27 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	a;
	unsigned char	cc;
	const char		*i;
	char			*d;

	a = 0;
	cc = c;
	i = src;
	d = dst;
	while (a < n)
	{
		if ((unsigned char)i[a] == cc)
		{
			*d = i[a];
			return ((void *)(d + 1));
		}
		*d = i[a];
		a++;
		d++;
	}
	return (NULL);
}
