/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:18:05 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting4(t_vars *v, int x)
{
	if (v->ray.side == 0)
	{
		v->ray.txt_hit = (v->ray.mapx < v->ray.posx ? 'N' : 'S');
		v->ray.perpwalldist = (v->ray.mapx - v->ray.posx +
			(1 - v->ray.stepx) / 2) / v->ray.raydirx;
		v->ray.wallx = v->ray.posy + v->ray.perpwalldist * v->ray.raydiry;
	}
	else
	{
		v->ray.txt_hit = (v->ray.mapy < v->ray.posy ? 'W' : 'E');
		v->ray.perpwalldist = (v->ray.mapy - v->ray.posy +
			(1 - v->ray.stepy) / 2) / v->ray.raydiry;
		v->ray.wallx = v->ray.posx + v->ray.perpwalldist * v->ray.raydirx;
	}
	v->spr.zbuffer[x] = v->ray.perpwalldist;
	ft_put_texture(v);
	v->ray.lineheigth = (int)(v->screen.heigth / v->ray.perpwalldist);
	v->ray.drawstart = (-1 * v->ray.lineheigth) / 2 + v->screen.heigth / 2;
	if (v->ray.drawstart < 0)
		v->ray.drawstart = 0;
	v->ray.drawend = v->ray.lineheigth / 2 + v->screen.heigth / 2;
	if (v->ray.drawend >= v->screen.heigth)
		v->ray.drawend = v->screen.heigth - 1;
	v->ray.wallx -= floor(v->ray.wallx);
}

void	ft_raycasting3(t_vars *v)
{
	while (v->ray.hit == 0)
	{
		if (v->ray.sidedistx < v->ray.sidedisty)
		{
			v->ray.sidedistx += v->ray.deltadistx;
			v->ray.mapx += v->ray.stepx;
			v->ray.side = 0;
		}
		else
		{
			v->ray.sidedisty += v->ray.deltadisty;
			v->ray.mapy += v->ray.stepy;
			v->ray.side = 1;
		}
		if (v->map.matrix_map[v->ray.mapx][v->ray.mapy] == 1)
			v->ray.hit = 1;
	}
}

void	ft_raycasting2(t_vars *v)
{
	v->ray.deltadistx = fabs(1 / v->ray.raydirx);
	v->ray.deltadisty = fabs(1 / v->ray.raydiry);
	if (v->ray.raydirx < 0)
	{
		v->ray.stepx = -1;
		v->ray.sidedistx = (v->ray.posx - v->ray.mapx) * v->ray.deltadistx;
	}
	else
	{
		v->ray.stepx = 1;
		v->ray.sidedistx = (v->ray.mapx + 1.0 - v->ray.posx) *
			v->ray.deltadistx;
	}
	if (v->ray.raydiry < 0)
	{
		v->ray.stepy = -1;
		v->ray.sidedisty = (v->ray.posy - v->ray.mapy) * v->ray.deltadisty;
	}
	else
	{
		v->ray.stepy = 1;
		v->ray.sidedisty = (v->ray.mapy + 1.0 - v->ray.posy) *
			v->ray.deltadisty;
	}
	v->ray.hit = 0;
}

void	ft_raycasting(t_vars *v)
{
	int	x;

	x = 0;
	while (x < v->screen.width)
	{
		v->ray.camerax = 2 * x / (double)v->screen.width - 1;
		v->ray.raydirx = v->ray.dirx + v->ray.planex * v->ray.camerax;
		v->ray.raydiry = v->ray.diry + v->ray.planey * v->ray.camerax;
		v->ray.mapx = (int)v->ray.posx;
		v->ray.mapy = (int)v->ray.posy;
		ft_raycasting2(v);
		ft_raycasting3(v);
		ft_raycasting4(v, x);
		v->txt.txt_x = v->ray.wallx * (v->txt.txt_sl / 4);
		if ((v->ray.side == 0 && v->ray.raydirx > 0) || (v->ray.side ==
			1 && v->ray.raydiry < 0))
			v->txt.txt_x = (v->txt.txt_sl / 4) - v->txt.txt_x - 1;
		ft_drawline(v, x);
		x++;
	}
}
