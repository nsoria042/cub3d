/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargesprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:49:26 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/14 10:13:01 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_count_sprites(t_vars *v)
{
	int m;
	int n;

	n = 0;
	while (n < v->map.nlines_map)
	{
		m = 0;
		while (m < v->map.mcol_map)
		{
			if (v->map.matrix_map[n][m] == 2)
				v->spr.cspr++;
			m++;
		}
		n++;
	}
}

void	ft_charge_sprites(t_vars *v, int m, int n, int i)
{
	ft_count_sprites(v);
	v->spr.sprx = malloc(v->spr.cspr * sizeof(int));
	v->spr.spry = malloc(v->spr.cspr * sizeof(int));
	v->spr.sortpprx = malloc(v->spr.cspr * sizeof(int));
	v->spr.sortppry = malloc(v->spr.cspr * sizeof(int));
	n = 0;
	i = 0;
	while (n < v->map.nlines_map)
	{
		m = 0;
		while (m < v->map.mcol_map)
		{
			if (v->map.matrix_map[n][m] == 2)
			{
				v->spr.sprx[i] = n;
				v->spr.spry[i] = m;
				v->spr.sortpprx[i] = n;
				v->spr.sortppry[i] = m;
				i++;
			}
			m++;
		}
		n++;
	}
}
