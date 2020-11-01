/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:08:25 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/14 16:31:52 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			t;
	void			*x;
	char			*str;
	unsigned int	a;

	a = 0;
	t = count * size;
	if (!(x = (void *)malloc(count * size)))
		return (NULL);
	str = (char *)x;
	while (a < t)
	{
		str[a] = '\0';
		a++;
	}
	return (x);
}
