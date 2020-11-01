/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_param2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:07:00 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ini_param6(t_vars *v)
{
	t_sprites	spr;

	spr.cspr = 0;
	v->spr = spr;
}

void			ini_param5(t_vars *v)
{
	t_control	control;

	control.c_keyup = 0;
	control.c_keydown = 0;
	control.c_keyleft = 0;
	control.c_keyright = 0;
	control.c_rotleft = 0;
	control.c_rotright = 0;
	v->control = control;
	ini_param6(v);
}
