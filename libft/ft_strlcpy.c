/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:19:37 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:32:36 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	b = 0;
	if (dst == NULL || src == NULL)
		return ((size_t)NULL);
	while (src[b] != '\0')
		++b;
	if (dstsize == 0)
		return (b);
	a = 0;
	while (src[a] != '\0' && a < (dstsize - 1))
	{
		dst[a] = src[a];
		++a;
	}
	dst[a] = '\0';
	return (b);
}
