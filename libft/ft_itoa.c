/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:02:11 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/06 12:23:22 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_number(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + ft_number(nb / 10));
}

static char		*ft_itoa2(char *str, int num, int i)
{
	unsigned int a;

	a = 0;
	if (num == 0)
		*str = num + 48;
	else if (num < 0)
	{
		*str = '-';
		a = num * -1;
	}
	else
		a = num;
	str[i + 1] = '\0';
	while (a != 0)
	{
		str[i] = a % 10 + 48;
		a = a / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n > 0)
		len = ft_number(n) - 1;
	else
		len = ft_number(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_itoa2(str, n, len - 1));
}
