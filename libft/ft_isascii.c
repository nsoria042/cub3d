/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:25:14 by isoria-g          #+#    #+#             */
/*   Updated: 2020/01/18 20:12:59 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (c >= 256)
		return (0);
	if ((a >= 0) && (a <= 127))
		return (1);
	return (0);
}