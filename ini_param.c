/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:10:08 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ini_param4(t_vars *v)
{
	t_texture	txt;

	txt.txt_x = 0;
	v->txt = txt;
	ini_param5(v);
}

void			ini_param3(t_vars *v)
{
	t_ray		ray;

	ray.posx = 0;
	ray.posy = 0;
	ray.dirx = -1;
	ray.diry = 0;
	ray.planex = 0;
	ray.planey = 0.66;
	ray.camerax = 0;
	ray.mapx = 0;
	ray.mapy = 0;
	ray.raydirx = 0;
	ray.raydiry = 0;
	ray.txtpos = 0;
	ray.txtstep = 0;
	ray.movespeed = MSPEED;
	ray.rotspeed = RSPEED;
	v->ray = ray;
	ini_param4(v);
}

void			ini_param2(t_vars *v)
{
	t_screen	screen;

	screen.width = WIN_WIDTH;
	screen.heigth = WIN_HEIGHT;
	screen.delay = 30;
	screen.fov = 60;
	screen.fov2 = v->screen.fov / 2;
	screen.pp_map = 0;
	screen.x = 0;
	screen.y = 0;
	screen.pangle = 90;
	screen.rcia = v->screen.fov / v->screen.width;
	screen.rcp = 64;
	v->screen = screen;
	ini_param3(v);
}

void			ini_param(t_vars *v)
{
	t_map		map;

	map.r_map = 0;
	map.no_map = 0;
	map.so_map = 0;
	map.we_map = 0;
	map.ea_map = 0;
	map.s_map = 0;
	map.f_map = 0;
	map.c_map = 0;
	map.ok_map = 0;
	map.cc_map = 0;
	map.c_savescr = 0;
	map.set = "NOSWEA ";
	map.lines_map = 0;
	map.nlines_map = 0;
	map.mcol_map = 0;
	map.nov_map = NULL;
	map.sov_map = NULL;
	map.wev_map = NULL;
	map.eav_map = NULL;
	map.matrix_map = NULL;
	v->map = map;
	ini_param2(v);
}
