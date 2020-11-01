/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:23:43 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 13:44:23 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_game(t_vars *v)
{
	ft_movement(v);
	ft_raycasting(v);
	ft_draw_sprites(v);
	if (v->map.c_savescr == 0)
		mlx_put_image_to_window(v->mlx.mlx_ptr, v->mlx.win,
			v->mlx.img.img_ptr, 0, 0);
	return (0);
}

int			main(int nargs, char **args)
{
	t_vars	v;

	if (nargs < 2)
		ft_error("Error\n No son suficientes argumentos\n", &v);
	if (nargs > 3)
		ft_error("Error\n Demasiados argumentos\n", &v);
	ini_param(&v);
	ft_parse(&v, args[1]);
	v.mlx.mlx_ptr = mlx_init();
	ft_charge_textures(&v);
	v.mlx.img.img_ptr = mlx_new_image(v.mlx.mlx_ptr, v.screen.width,
		v.screen.heigth);
	v.mlx.img.data = (int *)mlx_get_data_addr(v.mlx.img.img_ptr,
		&v.mlx.img.bpp, &v.mlx.img.size_l, &v.mlx.img.endian);
	if (nargs == 3)
		ft_screenshot(args[2], &v);
	v.mlx.win = mlx_new_window(v.mlx.mlx_ptr, v.screen.width,
		v.screen.heigth, "cub3D");
	mlx_hook(v.mlx.win, 2, 1, ft_keyup, (void *)&v);
	mlx_key_hook(v.mlx.win, ft_keydown, (void *)&v);
	mlx_hook(v.mlx.win, 17, 1, ft_close, (void *)&v);
	mlx_loop_hook(v.mlx.mlx_ptr, ft_game, (void *)&v);
	mlx_loop(v.mlx.mlx_ptr);
	return (0);
}
