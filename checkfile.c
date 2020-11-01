/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:54:11 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 11:49:57 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free2d(char **ptr)
{
	int	i;

	i = 0;
	while (*(ptr + i))
		free(*(ptr + i++));
	free(ptr);
}

void	ft_check_var(t_vars *v)
{
	if (v->map.r_map == 0)
		ft_error("Error\n No pasados valores para Width y Heigth\n", v);
	if (v->map.no_map == 0)
		ft_error("Error\n No pasada ruta para textura cara Norte\n", v);
	if (v->map.so_map == 0)
		ft_error("Error\n No pasada ruta para textura cara Sur\n", v);
	if (v->map.we_map == 0)
		ft_error("Error\n No pasada ruta para textura cara Oeste\n", v);
	if (v->map.ea_map == 0)
		ft_error("Error\n No pasada ruta para textura cara Este\n", v);
	if (v->map.s_map == 0)
		ft_error("Error\n No pasada ruta para textura cara Sprite\n", v);
	if (v->map.f_map == 0)
		ft_error("Error\n No pasado color para el Floor\n", v);
	if (v->map.c_map == 0)
		ft_error("Error\n No pasado color para el Ceiling\n", v);
}

void	ft_check_file(t_vars *v, char **line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp((const char*)line[i], "R ", 2) == 0 ||
			ft_strncmp((const char*)line[i], "NO ", 3) == 0 ||
			ft_strncmp((const char*)line[i], "SO ", 3) == 0 ||
			ft_strncmp((const char*)line[i], "WE ", 3) == 0 ||
			ft_strncmp((const char*)line[i], "EA ", 3) == 0 ||
			ft_strncmp((const char*)line[i], "F ", 2) == 0 ||
			ft_strncmp((const char*)line[i], "C ", 2) == 0 ||
			ft_strncmp((const char*)line[i], "S ", 2) == 0)
			ft_charge_var(v, line[i]);
		else if (ft_strlen((const char*)line[i]) == 0)
			line[i] = line[i];
		else if (v->map.cc_map == 0)
			ft_charge_map(v, &line[i]);
		i++;
	}
	ft_check_var(v);
}
