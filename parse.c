/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:23:43 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/20 12:22:33 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_get_number_lines(int fd)
{
	int		i;
	int		ret;
	char	*str;

	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &str);
		free(str);
		i++;
	}
	return (i);
}

char		**ft_get_file(int fd, char **temp, char **lines)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		temp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		if (temp)
			while (temp[j])
			{
				lines[j] = temp[j];
				j++;
			}
		free(temp);
		lines[j++] = s;
		lines[j] = 0;
		i++;
	}
	return (lines);
}

void		ft_charge_textures(t_vars *v)
{
	v->txt.txtn = mlx_xpm_file_to_image(v->mlx.mlx_ptr, v->map.nov_map,
		&v->txt.txtn_w, &v->txt.txtn_h);
	v->txt.txtn_data = (int *)mlx_get_data_addr(v->txt.txtn, &v->txt.txtn_sb,
		&v->txt.txtn_sl, &v->txt.txtn_ed);
	v->txt.txts = mlx_xpm_file_to_image(v->mlx.mlx_ptr, v->map.sov_map,
		&v->txt.txts_w, &v->txt.txts_h);
	v->txt.txts_data = (int *)mlx_get_data_addr(v->txt.txts, &v->txt.txts_sb,
		&v->txt.txts_sl, &v->txt.txts_ed);
	v->txt.txtw = mlx_xpm_file_to_image(v->mlx.mlx_ptr, v->map.wev_map,
		&v->txt.txtw_w, &v->txt.txtw_h);
	v->txt.txtw_data = (int *)mlx_get_data_addr(v->txt.txtw, &v->txt.txtw_sb,
		&v->txt.txtw_sl, &v->txt.txtw_ed);
	v->txt.txte = mlx_xpm_file_to_image(v->mlx.mlx_ptr, v->map.eav_map,
		&v->txt.txte_w, &v->txt.txte_h);
	v->txt.txte_data = (int *)mlx_get_data_addr(v->txt.txte, &v->txt.txte_sb,
		&v->txt.txte_sl, &v->txt.txte_ed);
	v->txt.txtp = mlx_xpm_file_to_image(v->mlx.mlx_ptr, v->map.sv_map,
		&v->txt.txtp_w, &v->txt.txtp_h);
	v->txt.txtp_data = (int *)mlx_get_data_addr(v->txt.txtp, &v->txt.txtp_sb,
		&v->txt.txtp_sl, &v->txt.txtp_ed);
}

void		ft_parse(t_vars *v, char *str)
{
	int		fd;
	char	**temp;
	int		nlines;

	temp = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Error\n Fichero mapa no encontrado\n", v);
	nlines = ft_get_number_lines(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	v->map.lines_file = 0;
	v->map.lines_file = ft_get_file(fd, temp, v->map.lines_file);
	close(fd);
	ft_check_file(v, v->map.lines_file);
	ft_charge_sprites(v, 0, 0, 0);
}
