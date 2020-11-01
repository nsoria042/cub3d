/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:23:52 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/15 13:56:09 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_rgb_int(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

void	ft_put_texture(t_vars *v)
{
	if (v->ray.txt_hit == 'N')
	{
		v->txt.txt_data = v->txt.txtn_data;
		v->txt.txt_sl = v->txt.txtn_sl;
		v->txt.txt_h = v->txt.txtn_h;
	}
	else if (v->ray.txt_hit == 'S')
	{
		v->txt.txt_data = v->txt.txts_data;
		v->txt.txt_sl = v->txt.txts_sl;
		v->txt.txt_h = v->txt.txts_h;
	}
	else if (v->ray.txt_hit == 'W')
	{
		v->txt.txt_data = v->txt.txtw_data;
		v->txt.txt_sl = v->txt.txtw_sl;
		v->txt.txt_h = v->txt.txtw_h;
	}
	else
	{
		v->txt.txt_data = v->txt.txte_data;
		v->txt.txt_sl = v->txt.txte_sl;
		v->txt.txt_h = v->txt.txte_h;
	}
}

void	ft_drawline(t_vars *v, int x)
{
	int		i;

	i = -1;
	v->ray.txtstep = 1.0 * v->txt.txt_h / v->ray.lineheigth;
	v->ray.txtpos = (v->ray.drawstart - v->screen.heigth / 2 +
		v->ray.lineheigth / 2) * v->ray.txtstep;
	while (++i < v->ray.drawstart)
		*(v->mlx.img.data + x + i * v->mlx.img.size_l / 4) =
			ft_rgb_int(v->map.cv_r_map, v->map.cv_g_map, v->map.cv_b_map);
	while (i <= v->ray.drawend - 1)
	{
		*(v->mlx.img.data + x + i * v->mlx.img.size_l / 4) =
			*(v->txt.txt_data + v->txt.txt_x + (int)v->ray.txtpos *
			v->txt.txt_sl / 4);
		i++;
		v->ray.txtpos += v->ray.txtstep;
	}
	while (i < v->screen.heigth)
	{
		*(v->mlx.img.data + x + i * v->mlx.img.size_l / 4) =
			ft_rgb_int(v->map.fv_r_map, v->map.fv_g_map, v->map.fv_b_map);
		i++;
	}
}
