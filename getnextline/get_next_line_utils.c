/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:24:27 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/17 14:41:39 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	a;
	unsigned int	l;
	char			*t;

	a = 0;
	l = (unsigned int)ft_strlen((char *)s1);
	if (!(t = (char *)malloc(l + 1)))
		return (NULL);
	while (a < l)
	{
		t[a] = s1[a];
		a++;
	}
	t[a] = '\0';
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0')
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}

int		ft_streol(const char *s)
{
	int		a;
	char	*string;

	a = 0;
	string = (char *)s;
	while (string[a] != '\0')
	{
		if (string[a] == '\n')
			return (a);
		a++;
	}
	if (string[a] == '\0' && string[a] == '\n')
		return (a);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
