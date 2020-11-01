/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:49:20 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/06 12:06:24 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s1, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			a = 0;
		else if (a == 0)
		{
			a = 1;
			b++;
		}
		s1++;
	}
	return (b);
}

static int		ft_letters(char const *s2, char c, int a)
{
	int	len;

	len = 0;
	while (s2[a] != c && s2[a] != '\0')
	{
		len++;
		a++;
	}
	return (len);
}

static char		**ft_clean(char const **str, int b)
{
	while (b > 0)
	{
		b--;
		free((void *)str[b]);
	}
	free(str);
	return (NULL);
}

static char		**ft_divide(char const *s, char **str, char c, int n)
{
	int	a;
	int	b;
	int	d;

	a = 0;
	b = 0;
	while (s[a] != '\0' && b < n)
	{
		d = 0;
		while (s[a] == c)
			a++;
		str[b] = (char *)malloc(sizeof(char) * ft_letters(s, c, a) + 1);
		if (str[b] == NULL)
			return (ft_clean((char const **)str, b));
		while (s[a] != '\0' && s[a] != c)
		{
			str[b][d] = s[a];
			a++;
			d++;
		}
		str[b][d] = '\0';
		b++;
	}
	str[b] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	return (ft_divide(s, str, c, n));
}
