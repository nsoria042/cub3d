/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:06:47 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/10 16:18:00 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	a;
	const char		*i;
	const char		*d;

	a = 0;
	i = s1;
	d = s2;
	while (a < n)
	{
		if (i[a] != d[a])
			return ((unsigned char)i[a] - ((unsigned char)d[a]));
		a++;
	}
	return (0);
}
