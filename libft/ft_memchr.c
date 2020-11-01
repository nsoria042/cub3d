/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:10:17 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/10 13:22:06 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	const char		*str;
	unsigned int	a;

	cc = c;
	a = 0;
	str = s;
	while (a < n)
	{
		if ((unsigned char)*str == cc)
			return ((void *)str);
		a++;
		str++;
	}
	return (NULL);
}
