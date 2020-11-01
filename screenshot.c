/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:38:42 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/21 08:40:54 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_int_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)i;
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int					ft_bmp_header(t_vars *v, int fd, int ps)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (v->screen.width * 3 * v->screen.heigth) +
		(ps * v->screen.heigth);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_int_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_int_char(header + 18, v->screen.width);
	ft_int_char(header + 22, v->screen.heigth);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int					ft_bmp_data(t_vars *v, int fd, int ps)
{
	unsigned char	zero[3];
	int				n;
	int				m;
	int				color;

	n = v->screen.heigth - 1;
	ft_bzero(zero, 3);
	while (n >= 0)
	{
		m = 0;
		while (m < v->screen.width)
		{
			color = *(v->mlx.img.data + m + n * v->mlx.img.size_l / 4);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (ps > 0 && write(fd, &zero, ps) < 0)
				return (0);
			m++;
		}
		n--;
	}
	return (1);
}

int					ft_save_screen(t_vars *v)
{
	int				fd;
	int				padsize;

	ft_game(v);
	padsize = (4 - (v->screen.width * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777 |
		O_TRUNC | O_APPEND)) < 0)
		return (0);
	ft_bmp_header(v, fd, padsize);
	ft_bmp_data(v, fd, padsize);
	close(fd);
	return (1);
}

void				ft_screenshot(char *str, t_vars *v)
{
	if (ft_strncmp("--save", str, 7) != 0)
		ft_error("Error\n Segundo argumento incorrecto", v);
	v->map.c_savescr = 1;
	if (!ft_save_screen(v))
		ft_error("Error\n No se ha generado el fichero screenshot.bmp", v);
	ft_close(v, 1);
}
