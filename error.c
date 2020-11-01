/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:01:02 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/21 08:45:46 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_vars *v)
{
	int	i;

	i = 0;
	if (v->map.matrix_map)
	{
		while (i < v->map.nlines_map)
		{
			free(v->map.matrix_map[i]);
			i++;
		}
	}
	i = 0;
	if (v->map.mirror_map)
	{
		while (i < v->map.nlines_map)
		{
			free(v->map.mirror_map[i]);
			i++;
		}
	}
}

int		ft_close(t_vars *v, int n)
{
	int	i;

	i = 0;
	if (v->map.lines_file)
	{
		while (v->map.lines_file[i])
		{
			free(v->map.lines_file[i]);
			i++;
		}
		free(v->map.lines_file);
	}
	ft_free(v);
	if (n == 0)
		mlx_destroy_window(v->mlx.mlx_ptr, v->mlx.win);
	free(v->mlx.mlx_ptr);
	exit(0);
}

void	ft_error(char *str, t_vars *v)
{
	write(2, str, ft_strlen(str));
	ft_close(v, 1);
}
