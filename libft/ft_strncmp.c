/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:39:52 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/29 11:20:10 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	int		res;

	if (n == 0)
		return (0);
	a = 0;
	res = 0;
	while (a < n && s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			res = (unsigned char)s1[a] - (unsigned char)s2[a];
			return (res);
		}
		a++;
	}
	if ((s1[a] == '\0' || s2[a] == '\0') && a != n)
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	return (res);
}
