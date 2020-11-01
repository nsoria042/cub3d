/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 10:54:43 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 10:24:45 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_perimeter(t_vars *v)
{
	int	n;
	int m;

	m = 0;
	while (m <= v->map.mcol_map - 1)
	{
		if ((v->map.matrix_map[0][m] != 9 && v->map.matrix_map[0][m] != 1) ||
			(v->map.matrix_map[v->map.nlines_map - 1][m] != 9 &&
			v->map.matrix_map[v->map.nlines_map - 1][m] != 1))
			ft_error("Error\n Mapa no cerrado por muros", v);
		m++;
	}
	n = 0;
	while (n <= v->map.nlines_map - 1)
	{
		if ((v->map.matrix_map[n][0] != 9 && v->map.matrix_map[n][0] != 1) ||
			(v->map.matrix_map[n][v->map.mcol_map - 1] != 9 &&
			v->map.matrix_map[n][v->map.mcol_map - 1] != 1))
			ft_error("Error\n Mapa no cerrado por muros", v);
		n++;
	}
}

void	ft_ini_mirror(t_vars *v)
{
	int m;
	int n;

	printf("nlines:%d\n", v->map.nlines_map);
	printf("mlines:%d\n", v->map.mcol_map);
	n = 0;
	v->map.mirror_map = malloc((v->map.nlines_map + 1) * sizeof(int *));
	while (n < v->map.nlines_map)
	{
		v->map.mirror_map[n] = malloc((v->map.mcol_map + 1) * sizeof(int));
		m = 0;
		while (m < v->map.mcol_map)
			v->map.mirror_map[n][m++] = 9;
		n++;
	}
}

void	ft_charge_mirror(t_vars *v)
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
			v->map.mirror_map[n][m] = (v->map.lines_map[n][m] == '1' ?
				1 : 6);
			m++;
		}
		n++;
	}
}

void	ft_check_map_inside(t_vars *v)
{
	int	n;
	int m;

	n = 1;
	while (n < v->map.nlines_map - 1)
	{
		m = 1;
		while (m < v->map.mcol_map - 1)
		{
			if (v->map.mirror_map[n][m] == 6 &&
				(v->map.mirror_map[n - 1][m - 1] == 9 ||
				v->map.mirror_map[n - 1][m] == 9 ||
				v->map.mirror_map[n - 1][m + 1] == 9 ||
				v->map.mirror_map[n][m - 1] == 9 ||
				v->map.mirror_map[n][m + 1] == 9 ||
				v->map.mirror_map[n + 1][m - 1] == 9 ||
				v->map.mirror_map[n + 1][m] == 9 ||
				v->map.mirror_map[n + 1][m + 1] == 9))
				ft_error("Error\n Mapa no cerrado por muros", v);
			m++;
		}
		n++;
	}
}

void	ft_check_map2(t_vars *v)
{
	if (v->screen.pp_map == 0)
		ft_error("Error\n Falta la posición del jugador en el mapa", v);
	ft_check_map3(v);
	ft_check_map_perimeter(v);
	ft_ini_mirror(v);
	ft_charge_mirror(v);
	ft_check_map_inside(v);
	v->map.ok_map = 1;
}
