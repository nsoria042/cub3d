/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:17:33 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_allow_move(int a)
{
	if (a == 1 || a == 2)
		return (0);
	return (1);
}

void	ft_movement3(t_vars *v)
{
	v->ray.olddirx = v->ray.dirx;
	v->ray.oldplanex = v->ray.planex;
	if (v->control.c_rotright == 1)
	{
		v->ray.dirx = v->ray.dirx * cos(-v->ray.rotspeed) - v->ray.diry *
			sin(-v->ray.rotspeed);
		v->ray.diry = v->ray.olddirx * sin(-v->ray.rotspeed) + v->ray.diry *
			cos(-v->ray.rotspeed);
		v->ray.planex = v->ray.planex * cos(-v->ray.rotspeed) - v->ray.planey *
			sin(-v->ray.rotspeed);
		v->ray.planey = v->ray.oldplanex * sin(-v->ray.rotspeed) +
			v->ray.planey * cos(-v->ray.rotspeed);
	}
	if (v->control.c_rotleft == 1)
	{
		v->ray.dirx = v->ray.dirx * cos(v->ray.rotspeed) - v->ray.diry *
			sin(v->ray.rotspeed);
		v->ray.diry = v->ray.olddirx * sin(v->ray.rotspeed) + v->ray.diry *
			cos(v->ray.rotspeed);
		v->ray.planex = v->ray.planex * cos(v->ray.rotspeed) - v->ray.planey *
			sin(v->ray.rotspeed);
		v->ray.planey = v->ray.oldplanex * sin(v->ray.rotspeed) +
			v->ray.planey * cos(v->ray.rotspeed);
	}
}

void	ft_movement2(t_vars *v)
{
	if (v->control.c_keyleft == 1)
	{
		if (ft_allow_move(v->map.matrix_map[(int)v->ray.posx][(int)
			(v->ray.posy + v->ray.dirx * v->ray.movespeed)]))
			v->ray.posy += v->ray.dirx * v->ray.movespeed;
		if (ft_allow_move(v->map.matrix_map[(int)(v->ray.posx - v->ray.diry *
			v->ray.movespeed)][(int)(v->ray.posy)]))
			v->ray.posx -= v->ray.diry * v->ray.movespeed;
	}
	if (v->control.c_keyright == 1)
	{
		if (ft_allow_move(v->map.matrix_map[(int)v->ray.posx][(int)
			(v->ray.posy - v->ray.dirx * v->ray.movespeed)]))
			v->ray.posy -= v->ray.dirx * v->ray.movespeed;
		if (ft_allow_move(v->map.matrix_map[(int)(v->ray.posx + v->ray.diry *
			v->ray.movespeed)][(int)(v->ray.posy)]))
			v->ray.posx += v->ray.diry * v->ray.movespeed;
	}
	ft_movement3(v);
}

void	ft_movement(t_vars *v)
{
	if (v->control.c_keyup == 1)
	{
		if (ft_allow_move(v->map.matrix_map[(int)(v->ray.posx + v->ray.dirx *
			v->ray.movespeed)][(int)v->ray.posy]))
			v->ray.posx += v->ray.dirx * v->ray.movespeed;
		if (ft_allow_move(v->map.matrix_map[(int)v->ray.posx][(int)
			(v->ray.posy + v->ray.diry * v->ray.movespeed)]))
			v->ray.posy += v->ray.diry * v->ray.movespeed;
	}
	if (v->control.c_keydown == 1)
	{
		if (ft_allow_move(v->map.matrix_map[(int)(v->ray.posx - v->ray.dirx *
			v->ray.movespeed)][(int)v->ray.posy]))
			v->ray.posx -= v->ray.dirx * v->ray.movespeed;
		if (ft_allow_move(v->map.matrix_map[(int)v->ray.posx][(int)
			(v->ray.posy - v->ray.diry * v->ray.movespeed)]))
			v->ray.posy -= v->ray.diry * v->ray.movespeed;
	}
	ft_movement2(v);
}
