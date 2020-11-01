/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:28:11 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:14:52 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnstr2(char *str1, char *str2, int n)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	c = (size_t)n;
	while (a < c)
	{
		b = 0;
		while (str1[a + b] == str2[b] && (a + b < c) &&
			(str1[a + b] != '\0' && str2[b] != '\0'))
			b++;
		if (b == ft_strlen((const char *)str2))
			return (&str1[a]);
		a++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	n;

	if (*needle == 0)
		return ((char *)haystack);
	str1 = (char *)haystack;
	str2 = (char *)needle;
	n = len;
	if (ft_strlen((const char *)str2) > ft_strlen((const char *)str1))
		return (NULL);
	if (str2 == '\0' || ft_strlen((const char*)str2) == 0 ||
		((str1 == str2) && (len == (size_t)ft_strlen((const char*)str1) + 1)))
		return ((char *)str1);
	if ((n + ft_strlen((const char *)str2)) > ft_strlen((const char *)str1)
		&& n != ft_strlen((const char *)str1))
		n = ft_strlen((const char *)str1) - ft_strlen((const char *)str2);
	return (ft_strnstr2(str1, str2, n));
}
