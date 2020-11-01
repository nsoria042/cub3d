/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:19:27 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/20 07:17:10 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	a;
	unsigned int	l;
	char			*t;
	char			*str1;

	a = 0;
	l = (unsigned int)ft_strlen((char *)s1);
	if (!(t = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1)))
		return (NULL);
	str1 = (char *)t;
	while (a < l)
	{
		str1[a] = s1[a];
		a++;
	}
	str1[a] = '\0';
	return (t);
}
