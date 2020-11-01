/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:46:27 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/06 09:22:55 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int a;

	if (n < 0)
	{
		a = (unsigned int)-n;
		ft_putchar_fd('-', fd);
	}
	else
		a = (unsigned int)n;
	if (a >= 10)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd(a % 10 + '0', fd);
}
