/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:16:44 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 10:25:44 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floodfill(t_vars *v, int n, int m)
{
	if (v->map.mirror_map[n][m] == -6)
		ft_error("Error\n Mapa no cerrado por muros", v);
	if (v->map.mirror_map[n][m] != 0)
		return ;
	v->map.mirror_map[n][m] = 1;
	ft_floodfill(v, n + 1, m);
	ft_floodfill(v, n - 1, m);
	ft_floodfill(v, n, m + 1);
	ft_floodfill(v, n, m - 1);
	ft_floodfill(v, n + 1, m + 1);
	ft_floodfill(v, n + 1, m - 1);
	ft_floodfill(v, n - 1, m + 1);
	ft_floodfill(v, n - 1, m - 1);
}

void	ft_ini_mirror2(t_vars *v)
{
	int m;
	int n;

	n = 0;
	v->map.mirror_map = malloc((v->map.nlines_map + 2) * sizeof(int *));
	while (n < v->map.nlines_map + 2)
	{
		v->map.mirror_map[n] = malloc((v->map.mcol_map + 2) * sizeof(int));
		m = 0;
		while (m < v->map.mcol_map + 2)
			v->map.mirror_map[n][m++] = -6;
		n++;
	}
}

void	ft_charge_mirror2(t_vars *v)
{
	int m;
	int n;

	n = 0;
	while (v->map.lines_map[n])
	{
		m = 0;
		while (v->map.lines_map[n][m])
		{
			while (v->map.lines_map[n][m] == ' ')
				m++;
			if (v->map.lines_map[n][m] == 'N' || v->map.lines_map[n][m] == 'S'
			|| v->map.lines_map[n][m] == 'E' || v->map.lines_map[n][m] == 'W'
			|| v->map.lines_map[n][m] == 50)
				v->map.mirror_map[n + 1][m + 1] = 0;
			else
				v->map.mirror_map[n + 1][m + 1] = v->map.lines_map[n][m] - 48;
			m++;
		}
		n++;
	}
}

void	ft_check_map3(t_vars *v)
{
	if (v->screen.pp_map == 0)
		ft_error("Error\n Falta la posición del jugador en el mapa", v);
	ft_ini_mirror2(v);
	ft_charge_mirror2(v);
	ft_floodfill(v, v->ray.posx, v->ray.posy);
	v->map.ok_map = 1;
}
