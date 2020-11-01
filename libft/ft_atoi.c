/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:47:59 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/19 14:25:51 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*ft_isspace(char *str)
{
	int i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (&str[i]);
}

static int		ft_compare_sign(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	if (flag % 2 == 0)
		return (1);
	return (-1);
}

static char		*ft_pos(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (&str[i]);
}

int				ft_atoi(const char *str)
{
	char	*ptr;
	int		i;
	int		j;
	int		nb;
	long	total;

	i = 0;
	ptr = ft_pos(ft_isspace((char *)str));
	if (ptr[0] < '0' || ptr[0] > '9')
		return (0);
	j = 0;
	while (ptr[j] >= '0' && ptr[j] <= '9')
		j++;
	i = 0;
	total = 0;
	while (i < j)
	{
		nb = ptr[i] - '0';
		total = total + nb;
		if (i < j - 1)
			total = total * 10;
		i++;
	}
	total = total * ft_compare_sign(ft_isspace((char *)str));
	return (total);
}
