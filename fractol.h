/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:20:09 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/11 11:37:31 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH			800
# define HEIGHT			600
# define IT_MAX			30

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_vars
{
	int					row;
	int					col;
	double				c_re;
	double				c_im;
	double				x;
	double				y;
	double				new_re;
	double				new_im;
	double				old_re;
	double				old_im;
	int					it;
	double				mratio;
}						t_vars;

typedef struct			s_info
{
	void				(*frac_ptr)(struct s_info *env, t_vars *v);
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_ptr;
	int					m_x;
	int					m_y;
	int					sl;
	int					endian;
	int					bpp;
	double				zoom;
	double				ox;
	double				oy;
	t_vars				*v;
	char				*frac_name;
	char				lock;
	int					it_max;
}						t_info;

int						tracing_main(t_info *env);
int						refresher(t_info *env);
void					core(t_info *env);
void					vars_init(t_info *env);
void					julia_fractal(t_info *env, t_vars *v);
void					mandel_fractal(t_info *env, t_vars *v);
void					boat_fractal(t_info *env, t_vars *v);
int						put_pxl(t_info *env, t_color color, int x, int y);
t_color					get_color(t_info *env, int it);
void					zoomed(t_info *env);
void					unzoomed(t_info *env);

#endif
