/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:44:02 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:31:31 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	a;
	size_t	b;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen((char *)src);
	if (dstsize <= dst_size)
		return (src_size + dstsize);
	b = 0;
	a = dst_size;
	while (a < dstsize - 1 && src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (src_size + dst_size);
}
