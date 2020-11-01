/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:30:26 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/06 09:57:30 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	a;
	size_t	len;

	a = 0;
	len = ft_strlen(set);
	while (a < len)
	{
		if (c == set[a])
			return (1);
		a++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;
	size_t	len;
	char	*str;

	a = 0;
	b = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_isinset(s1[a], set))
		a++;
	while (len > 0 && ft_isinset(s1[len - 1], set))
		len--;
	if (len < a)
		len = a;
	if (!(str = (char*)malloc(sizeof(char) * (len - a + 1))))
		return (NULL);
	while (a < len)
		str[b++] = s1[a++];
	str[b] = '\0';
	return (str);
}
