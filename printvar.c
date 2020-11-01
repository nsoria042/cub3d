/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 08:33:49 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/19 14:19:12 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print4(t_vars *v)
{
	int	i;

	i = 0;
	printf("----------------------\n");
	printf("posx:%f\n", v->ray.posx);
	printf("posy:%f\n", v->ray.posy);
	while (i < v->spr.cspr)
	{
		printf("sprPosX:%f\n", v->spr.sprx[i]);
		printf("sprPosY:%f\n", v->spr.spry[i]);
		printf("sortsprPosX:%f\n", v->spr.sortpprx[i]);
		printf("sortsprPosY:%f\n", v->spr.sortppry[i]);
		i++;
	}
}

void	ft_print3(t_vars *v)
{
	printf("txtpos:%f\n", v->ray.txtpos);
}

void	ft_print2(t_vars *v)
{
	printf("X:%f\n", v->ray.posx);
	printf("Y:%f\n", v->ray.posy);
	printf("mapx:%d\n", v->ray.mapx);
	printf("mapy:%d\n", v->ray.mapy);
}

void	ft_print(t_vars *v)
{
	printf("----------\n");
	printf("Contador R línea existe-%d\n", v->map.r_map);
	printf("Contador NO línea existe-%d\n", v->map.no_map);
	printf("Contador SO línea existe-%d\n", v->map.so_map);
	printf("Contador WE línea existe-%d\n", v->map.we_map);
	printf("Contador EA línea existe-%d\n", v->map.ea_map);
	printf("Contador S línea existe-%d\n", v->map.s_map);
	printf("Contador F línea existe-%d\n", v->map.f_map);
	printf("Contador C línea existe-%d\n", v->map.c_map);
	printf("Valor W de R-%d %d\n", v->map.rv_w_map, v->screen.width);
	printf("Valor H de R-%d %d\n", v->map.rv_h_map, v->screen.heigth);
	printf("Valor path NO-%s\n", v->map.nov_map);
	printf("Valor path SO-%s\n", v->map.sov_map);
	printf("Valor path WE-%s\n", v->map.wev_map);
	printf("Valor path EA-%s\n", v->map.eav_map);
	printf("Valor path S-%s\n", v->map.sv_map);
	printf("Valor R de F-%d\n", v->map.fv_r_map);
	printf("Valor G de F-%d\n", v->map.fv_g_map);
	printf("Valor B de F-%d\n", v->map.fv_b_map);
	printf("Valor R de C-%d\n", v->map.cv_r_map);
	printf("Valor G de C-%d\n", v->map.cv_g_map);
	printf("Valor B de C-%d\n", v->map.cv_b_map);
}
