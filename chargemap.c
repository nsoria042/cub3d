/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargemap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:51:42 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 10:24:54 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dimension_map(t_vars *v)
{
	int	j;

	j = 0;
	while (v->map.lines_map[j])
	{
		if ((int)ft_strlen((const char*)v->map.lines_map[j]) == 0)
			ft_error("Error\n Mapa pasado en el fichero incorrecto", v);
		else if ((int)ft_strlen((const char*)v->map.lines_map[j]) >
			v->map.mcol_map)
			v->map.mcol_map = ft_strlen((const char*)v->map.lines_map[j]);
		v->map.nlines_map++;
		j++;
	}
}

void	ft_ini_map(t_vars *v)
{
	int m;
	int n;

	n = 0;
	v->map.matrix_map = malloc((v->map.nlines_map + 1) * sizeof(int *));
	while (n < v->map.nlines_map)
	{
		v->map.matrix_map[n] = malloc((v->map.mcol_map + 1) * sizeof(int));
		m = 0;
		while (m < v->map.mcol_map)
		{
			v->map.matrix_map[n][m] = 9;
			m++;
		}
		n++;
	}
}

void	ft_check_map(t_vars *v, int n, int m)
{
	if (v->map.lines_map[n][m] == '0' ||
		v->map.lines_map[n][m] == '1' ||
		v->map.lines_map[n][m] == '2')
		v->map.matrix_map[n][m] = v->map.lines_map[n][m] - '0';
	else if (v->map.lines_map[n][m] == 'N' ||
		v->map.lines_map[n][m] == 'S' ||
		v->map.lines_map[n][m] == 'E' ||
		v->map.lines_map[n][m] == 'W')
	{
		if (v->screen.pp_map == 0)
		{
			v->screen.x = n;
			v->screen.y = m;
			v->map.matrix_map[n][m] = 0;
			ft_playerpos(v->map.lines_map[n][m], v);
			v->screen.pp_map = 1;
		}
		else
			ft_error("Error\n Posición duplicada en el mapa", v);
	}
	else
		ft_error("Error\n Caracter incorrecto en la estructura del mapa", v);
}

void	ft_fill_map(t_vars *v)
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
			if (v->map.lines_map[n][m])
				ft_check_map(v, n, m);
			m++;
		}
		n++;
	}
}

void	ft_charge_map(t_vars *v, char **line)
{
	v->map.cc_map = 1;
	v->map.lines_map = line;
	ft_dimension_map(v);
	ft_ini_map(v);
	ft_fill_map(v);
	ft_check_map3(v);
}
