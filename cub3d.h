/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:24:42 by isoria-g          #+#    #+#             */
/*   Updated: 2020/10/21 08:40:54 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIN_WIDTH 2520
# define WIN_HEIGHT 1380
# define KUP 13
# define KDOWN 1
# define KLEFT 0
# define KRIGHT 2
# define CLEFT 123
# define CRIGHT 124
# define MSPEED 0.07
# define RSPEED 0.03

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
}					t_mlx;

typedef	struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	char			txt_hit;
	double			wallx;
	double			txtstep;
	double			txtpos;
	int				lineheigth;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;

}					t_ray;

typedef struct		s_screen
{
	int				width;
	int				heigth;
	int				delay;
	float			fov;
	float			fov2;
	int				pp_map;
	double			x;
	double			y;
	float			pangle;
	float			rcia;
	float			rcp;
}					t_screen;

typedef struct		s_map
{
	int				r_map;
	int				no_map;
	int				so_map;
	int				we_map;
	int				ea_map;
	int				s_map;
	int				f_map;
	int				c_map;
	int				rv_w_map;
	int				rv_h_map;
	char			*nov_map;
	char			*sov_map;
	char			*wev_map;
	char			*eav_map;
	char			*sv_map;
	int				fv_r_map;
	int				fv_g_map;
	int				fv_b_map;
	int				cv_r_map;
	int				cv_g_map;
	int				cv_b_map;
	int				cc_map;
	int				ok_map;
	int				c_savescr;
	char const		*set;
	char			*line_file;
	int				nlines_file;
	char			**lines_file;
	char			**lines_map;
	int				nlines_map;
	int				mcol_map;
	int				**matrix_map;
	int				**mirror_map;
}					t_map;

typedef	struct		s_control
{
	int				c_keyup;
	int				c_keydown;
	int				c_keyleft;
	int				c_keyright;
	int				c_rotleft;
	int				c_rotright;
}					t_control;

typedef	struct		s_texture
{
	void			*txtn;
	int				*txtn_data;
	int				txtn_h;
	int				txtn_w;
	int				txtn_sl;
	int				txtn_sb;
	int				txtn_ed;
	void			*txts;
	int				*txts_data;
	int				txts_h;
	int				txts_w;
	int				txts_sl;
	int				txts_sb;
	int				txts_ed;
	void			*txtw;
	int				*txtw_data;
	int				txtw_h;
	int				txtw_w;
	int				txtw_sl;
	int				txtw_sb;
	int				txtw_ed;
	void			*txte;
	int				*txte_data;
	int				txte_h;
	int				txte_w;
	int				txte_sl;
	int				txte_sb;
	int				txte_ed;
	void			*txtp;
	int				*txtp_data;
	int				txtp_h;
	int				txtp_w;
	int				txtp_sl;
	int				txtp_sb;
	int				txtp_ed;
	int				*txt_data;
	int				txt_sl;
	int				txt_h;
	int				txt_x;
}					t_texture;

typedef	struct		s_sprites
{
	float			*sprx;
	float			*spry;
	float			*sortpprx;
	float			*sortppry;
	int				cspr;
	double			zbuffer[4320];
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	int				stripe;
	int				y;
	int				d;
}					t_sprites;

typedef struct		s_vars
{
	t_img			img;
	t_mlx			mlx;
	t_ray			ray;
	t_screen		screen;
	t_map			map;
	t_control		control;
	t_texture		txt;
	t_sprites		spr;
}					t_vars;

int					get_next_line(int fd, char **line);

void				ini_param(t_vars *v);
void				ini_param2(t_vars *v);
void				ini_param3(t_vars *v);
void				ini_param4(t_vars *v);

void				ini_param5(t_vars *v);
void				ini_param6(t_vars *v);

void				ft_error(char *str, t_vars *v);
int					ft_close(t_vars *v, int n);
void				ft_free(t_vars *v);

void				ft_parse(t_vars *v, char *str);
int					ft_get_number_lines(int fd);
char				**ft_get_file(int fd, char **temp, char **lines);
void				ft_charge_textures(t_vars *v);

void				ft_check_file(t_vars *v, char **line);
void				ft_free2d(char **ptr);
void				ft_check_var(t_vars *v);

int					ft_verify(t_vars *v);
void				ft_charge_var(t_vars *v, char *line);
void				ft_charge_var2(t_vars *v, char **sp);
void				ft_charge_var3(t_vars *v, char *line, const char *str);
void				ft_charge_var4(t_vars *v, char *line, char **sp, char c);

void				ft_checkpaths(t_vars *v, char *line, const char *str);

void				ft_charge_map(t_vars *v, char **line);
void				ft_fill_map(t_vars *v);
void				ft_check_map(t_vars *v, int n, int m);
void				ft_ini_map(t_vars *v);
void				ft_dimension_map(t_vars *v);

void				ft_check_map2(t_vars *v);
void				ft_check_map_inside(t_vars *v);
void				ft_charge_mirror(t_vars *v);
void				ft_ini_mirror(t_vars *v);
void				ft_check_map_perimeter(t_vars *v);

void				ft_check_map3(t_vars *v);
void				ft_charge_mirror2(t_vars *v);
void				ft_ini_mirror2(t_vars *v);
void				ft_floodfill(t_vars *v, int n, int m);

void				ft_playerpos(char d, t_vars *v);
void				ft_playerpos2(char d, t_vars *v);

void				ft_screenshot(char *str, t_vars *v);
int					ft_save_screen(t_vars *v);
int					ft_bmp_data(t_vars *v, int fd, int ps);
int					ft_bmp_header(t_vars *v, int fd, int ps);
void				ft_int_char(unsigned char *c, int i);

int					ft_keydown(int keycode, t_vars *v);
int					ft_keyup(int keycode, t_vars *v);

void				ft_raycasting(t_vars *v);
void				ft_raycasting2(t_vars *v);
void				ft_raycasting3(t_vars *v);
void				ft_raycasting4(t_vars *v, int x);

void				ft_drawline(t_vars *v, int x);
void				ft_put_texture(t_vars *v);
int					ft_rgb_int(int r, int g, int b);

void				ft_movement(t_vars *v);
void				ft_movement2(t_vars *v);
void				ft_movement3(t_vars *v);
int					ft_allow_move(int a);

void				ft_charge_sprites(t_vars *v, int m, int n, int i);
void				ft_count_sprites(t_vars *v);

void				ft_draw_sprites(t_vars *v);
void				ft_draw_sprites2(t_vars *v);
void				ft_draw_sprites3(t_vars *v);
void				ft_sort_sprites(t_vars *v, float tempx, float tempy,
						double dtemp);
void				ft_sort_sprites2(t_vars *v, float tempx, float tempy,
						int i);

void				ft_print(t_vars *v);
void				ft_print2(t_vars *v);
void				ft_print3(t_vars *v);
void				ft_print4(t_vars *v);

int					ft_game(t_vars *v);

#endif
