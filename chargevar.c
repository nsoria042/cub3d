/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargevar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:34:40 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/21 08:52:50 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_verify(t_vars *v)
{
	if ((v->map.fv_r_map >= 0 && v->map.fv_r_map <= 255) &&
		(v->map.fv_g_map >= 0 && v->map.fv_g_map <= 255) &&
		(v->map.fv_b_map >= 0 && v->map.fv_b_map <= 255) &&
		(v->map.cv_r_map >= 0 && v->map.cv_r_map <= 255) &&
		(v->map.cv_g_map >= 0 && v->map.cv_g_map <= 255) &&
		(v->map.cv_b_map >= 0 && v->map.cv_b_map <= 255))
		return (1);
	return (0);
}

void				ft_charge_var2(t_vars *v, char **sp)
{
	if ((sp[1] == NULL) || (sp[2] == NULL))
		ft_error("Error\n Faltan valores para Width o Heigth\n", v);
	v->map.rv_w_map = ft_atoi((const char*)sp[1]);
	v->map.rv_h_map = ft_atoi((const char*)sp[2]);
	v->screen.width = (v->map.rv_w_map > WIN_WIDTH ? WIN_WIDTH :
		v->map.rv_w_map);
	v->screen.heigth = (v->map.rv_h_map > WIN_HEIGHT ? WIN_HEIGHT :
		v->map.rv_h_map);
	v->map.r_map = 1;
}

void				ft_charge_var3(t_vars *v, char *line, const char *str)
{
	if (ft_strncmp((const char*)line, "NO ", 3) == 0)
	{
		v->map.nov_map = ft_strdup(str);
		v->map.no_map = 1;
	}
	else if (ft_strncmp((const char*)line, "SO ", 3) == 0)
	{
		v->map.sov_map = ft_strdup(str);
		v->map.so_map = 1;
	}
	else if (ft_strncmp((const char*)line, "WE ", 3) == 0)
	{
		v->map.wev_map = ft_strdup(str);
		v->map.we_map = 1;
	}
	else if (ft_strncmp((const char*)line, "EA ", 3) == 0)
	{
		v->map.eav_map = ft_strdup(str);
		v->map.ea_map = 1;
	}
	else
	{
		v->map.sv_map = ft_strdup(str);
		v->map.s_map = 1;
	}
}

void				ft_charge_var4(t_vars *v, char *line, char **sp, char c)
{
	char			**sp2;

	sp2 = ft_split((const char*)sp[1], c);
	if ((sp2[0] == NULL) || (sp2[1] == NULL) || (sp2[2] == NULL))
		ft_error("Error\n Faltan valores para Floor o Ceiling\n", v);
	if (ft_strncmp((const char*)line, "F", 1) == 0)
	{
		v->map.fv_r_map = ft_atoi((const char*)sp2[0]);
		v->map.fv_g_map = ft_atoi((const char*)sp2[1]);
		v->map.fv_b_map = ft_atoi((const char*)sp2[2]);
		if (ft_verify(v))
			v->map.f_map = 1;
	}
	else if (ft_strncmp((const char*)line, "C", 1) == 0)
	{
		v->map.cv_r_map = ft_atoi((const char*)sp2[0]);
		v->map.cv_g_map = ft_atoi((const char*)sp2[1]);
		v->map.cv_b_map = ft_atoi((const char*)sp2[2]);
		if (ft_verify(v))
			v->map.c_map = 1;
	}
	ft_free2d(sp2);
}

void				ft_charge_var(t_vars *v, char *line)
{
	char			**sp;
	const char		*str;

	sp = ft_split((const char*)line, 32);
	str = (const char*)ft_strtrim((const char*)line, v->map.set);
	if (ft_strncmp((const char*)line, "R", 1) == 0)
		ft_charge_var2(v, sp);
	else if ((ft_strncmp((const char*)line, "NO ", 3) == 0) ||
		(ft_strncmp((const char*)line, "SO ", 3) == 0) ||
		(ft_strncmp((const char*)line, "WE ", 3) == 0) ||
		(ft_strncmp((const char*)line, "EA ", 3) == 0) ||
		((ft_strncmp((const char*)line, "S ", 2) == 0) &&
		(ft_strncmp((const char*)line, "SO ", 3) != 0)))
		ft_checkpaths(v, line, str);
	else
		ft_charge_var4(v, line, sp, 44);
	free((void*)str);
	ft_free2d(sp);
}
