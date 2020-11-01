/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:16:36 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/15 13:24:20 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;
	unsigned char	cc;
	char			*string;

	a = 0;
	cc = c;
	string = (char *)s;
	while (string[a] != '\0')
	{
		if (string[a] == (unsigned char)cc)
			return (&string[a]);
		a++;
	}
	if (string[a] == '\0' && string[a] == (unsigned char)cc)
		return (&string[a]);
	return (NULL);
}
