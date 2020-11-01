/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:05:12 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_playerpos2(char d, t_vars *v)
{
	if (d == 'W')
	{
		v->ray.dirx = 0;
		v->ray.diry = -1;
		v->ray.planex = -0.66;
		v->ray.planey = 0;
	}
	else if (d == 'E')
	{
		v->ray.dirx = 0;
		v->ray.diry = 1;
		v->ray.planex = 0.66;
		v->ray.planey = 0;
	}
}

void	ft_playerpos(char d, t_vars *v)
{
	if (d != 'N' && d != 'S' && d != 'E' && d != 'W')
		ft_error("Error\n Carácter incorrecto en el mapa", v);
	v->ray.posx = v->screen.x + 0.5;
	v->ray.posy = v->screen.y + 0.5;
	if (d == 'N')
	{
		v->ray.dirx = -1;
		v->ray.diry = 0;
		v->ray.planex = 0;
		v->ray.planey = 0.66;
	}
	else if (d == 'S')
	{
		v->ray.dirx = 1;
		v->ray.diry = 0;
		v->ray.planex = 0;
		v->ray.planey = -0.66;
	}
	else
		ft_playerpos2(d, v);
}
