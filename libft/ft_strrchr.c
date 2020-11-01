/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:22:09 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/13 13:34:14 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	a;
	unsigned char	cc;
	char			*string;

	cc = c;
	string = (char *)s;
	a = ft_strlen(string);
	while (a > 0)
	{
		if (string[a] == (unsigned char)cc)
			return (&string[a]);
		a--;
	}
	if (a == 0 && string[a] == (unsigned char)cc)
		return (&string[a]);
	return (NULL);
}
