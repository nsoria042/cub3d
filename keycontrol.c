/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:47:22 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/21 08:40:54 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_keydown(int keycode, t_vars *v)
{
	if (keycode == KUP)
		v->control.c_keyup = 0;
	else if (keycode == KDOWN)
		v->control.c_keydown = 0;
	else if (keycode == KLEFT)
		v->control.c_keyleft = 0;
	else if (keycode == KRIGHT)
		v->control.c_keyright = 0;
	else if (keycode == CLEFT)
		v->control.c_rotleft = 0;
	else if (keycode == CRIGHT)
		v->control.c_rotright = 0;
	return (keycode);
}

int			ft_keyup(int keycode, t_vars *v)
{
	if (keycode == 53)
		ft_close(v, 0);
	else if (keycode == KUP)
		v->control.c_keyup = 1;
	else if (keycode == KDOWN)
		v->control.c_keydown = 1;
	else if (keycode == KLEFT)
		v->control.c_keyleft = 1;
	else if (keycode == KRIGHT)
		v->control.c_keyright = 1;
	else if (keycode == CLEFT)
		v->control.c_rotleft = 1;
	else if (keycode == CRIGHT)
		v->control.c_rotright = 1;
	return (keycode);
}
