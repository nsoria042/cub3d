/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:39:11 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/19 16:16:18 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*ft_memset(void *b, int c, size_t len)
{
	unsigned int	a;
	unsigned char	cc;
	unsigned char	*i;

	a = 0;
	cc = c;
	i = b;
	while (a < len)
	{
		*i = cc;
		i++;
		a++;
	}
	return (b);
}
