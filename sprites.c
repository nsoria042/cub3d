/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:53:17 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sort_sprites2(t_vars *v, float tempx, float tempy, int i)
{
	tempx = v->spr.sortpprx[i];
	tempy = v->spr.sortppry[i];
	v->spr.sortpprx[i] = v->spr.sortpprx[i + 1];
	v->spr.sortppry[i] = v->spr.sortppry[i + 1];
	v->spr.sortpprx[i + 1] = tempx;
	v->spr.sortppry[i + 1] = tempy;
}

void		ft_sort_sprites(t_vars *v, float tempx, float tempy, double dtemp)
{
	int		i;
	double	dist[v->spr.cspr];

	i = -1;
	while (++i < v->spr.cspr)
	{
		dist[i] = (pow((v->ray.posx - (double)v->spr.sprx[i]), 2) -
			pow((v->ray.posy - (double)v->spr.spry[i]), 2));
		v->spr.sortpprx[i] = v->spr.sprx[i];
		v->spr.sortppry[i] = v->spr.spry[i];
	}
	i = -1;
	while (++i < v->spr.cspr - 1)
	{
		if (fabs(dist[i]) < fabs(dist[i + 1]))
		{
			dtemp = dist[i];
			dist[i] = dist[i + 1];
			dist[i + 1] = dtemp;
			ft_sort_sprites2(v, tempx, tempy, i);
			i = -1;
		}
	}
}

void		ft_draw_sprites2(t_vars *v)
{
	v->spr.invdet = 1.0 / (v->ray.planex * v->ray.diry -
		v->ray.dirx * v->ray.planey);
	v->spr.transformx = v->spr.invdet * (v->ray.diry * v->spr.spritex -
		v->ray.dirx * v->spr.spritey);
	v->spr.transformy = v->spr.invdet * (-v->ray.planey * v->spr.spritex +
		v->ray.planex * v->spr.spritey);
	v->spr.spritescreenx = (int)((v->screen.width / 2) * (1 +
		v->spr.transformx / v->spr.transformy));
	v->spr.spriteheight = abs((int)(v->screen.heigth / v->spr.transformy));
	v->spr.drawstarty = -v->spr.spriteheight / 2 + v->screen.heigth / 2;
	if (v->spr.drawstarty < 0)
		v->spr.drawstarty = 0;
	v->spr.drawendy = v->spr.spriteheight / 2 + v->screen.heigth / 2;
	if (v->spr.drawendy >= v->screen.heigth)
		v->spr.drawendy = v->screen.heigth - 1;
	v->spr.spritewidth = abs((int)(v->screen.heigth / v->spr.transformy));
	v->spr.drawstartx = -v->spr.spritewidth / 2 + v->spr.spritescreenx;
	if (v->spr.drawstartx < 0)
		v->spr.drawstartx = 0;
	v->spr.drawendx = v->spr.spritewidth / 2 + v->spr.spritescreenx;
	if (v->spr.drawendx >= v->screen.width)
		v->spr.drawendx = v->screen.width - 1;
}

void		ft_draw_sprites3(t_vars *v)
{
	while (v->spr.stripe < v->spr.drawendx)
	{
		v->spr.texx = (int)((v->spr.stripe - (-v->spr.spritewidth / 2 +
			v->spr.spritescreenx)) * v->txt.txtp_w / v->spr.spritewidth);
		v->spr.y = v->spr.drawstarty;
		if (v->spr.transformy > 0 && v->spr.stripe >= 0 && v->spr.stripe <
			v->screen.width && v->spr.transformy <
			v->spr.zbuffer[v->spr.stripe])
			while (v->spr.y < v->spr.drawendy)
			{
				v->spr.d = (v->spr.y) * 256 - v->screen.heigth * 128 +
					v->spr.spriteheight * 128;
				v->spr.texy = ((v->spr.d * v->txt.txtp_h) /
					v->spr.spriteheight) / 256;
				if (*(v->txt.txtp_data + v->spr.texx + v->spr.texy *
					v->txt.txtp_sl / 4))
					*(v->mlx.img.data + v->spr.stripe + v->spr.y *
						v->mlx.img.size_l / 4) = *(v->txt.txtp_data +
						v->spr.texx + v->spr.texy * v->txt.txtp_sl / 4);
				v->spr.y++;
			}
		v->spr.stripe++;
	}
}

void		ft_draw_sprites(t_vars *v)
{
	int		i;

	ft_sort_sprites(v, 0, 0, 0);
	i = 0;
	while (i < v->spr.cspr)
	{
		v->spr.spritex = (v->spr.sortpprx[i] + 0.5) - v->ray.posx;
		v->spr.spritey = (v->spr.sortppry[i] + 0.5) - v->ray.posy;
		ft_draw_sprites2(v);
		v->spr.stripe = v->spr.drawstartx;
		ft_draw_sprites3(v);
		i++;
	}
}
