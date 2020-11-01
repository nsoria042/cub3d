/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargevar2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:05:40 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 10:39:21 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_checkpaths(t_vars *v, char *line, const char *str)
{
	int				fd;

	if ((ft_strncmp((const char*)line, "NO ", 3) == 0) && v->map.no_map == 1)
		ft_error("Error\n Más de un valor para la textura Norte", v);
	else if ((ft_strncmp((const char*)line, "SO ", 3) == 0) &&
		v->map.so_map == 1)
		ft_error("Error\n Más de un valor para la textura Sur", v);
	else if ((ft_strncmp((const char*)line, "WE ", 3) == 0) &&
		v->map.we_map == 1)
		ft_error("Error\n Más de un valor para la textura Oeste", v);
	else if ((ft_strncmp((const char*)line, "EA ", 3) == 0) &&
		v->map.ea_map == 1)
		ft_error("Error\n Más de un valor para la textura Este", v);
	else if (((ft_strncmp((const char*)line, "S ", 2) == 0) &&
		(ft_strncmp((const char*)line, "SO ", 3) != 0) && v->map.s_map == 1))
		ft_error("Error\n Más de un valor para la textura del Sprite", v);
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("Error\n Path incorrecto para la textura", v);
	close(fd);
	ft_charge_var3(v, line, str);
}
