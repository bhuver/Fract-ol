/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:48:21 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/17 13:49:18 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				vars_init(t_info *env)
{
	env->v->row = -1;
	env->v->col = -1;
	env->v->c_re = 0;
	env->v->c_im = 0;
	env->v->x = 0;
	env->v->y = 0;
	env->v->it = -1;
	env->v->old_re = 0;
	env->v->old_im = 0;
	env->v->new_re = 0;
	env->v->new_im = 0;
	env->v->mratio = (env->lock) ? env->v->mratio : env->m_x - env->m_y;
}

void				julia_fractal(t_info *env, t_vars *v)
{
	env->frac_name = ft_strdup("Julia's Fractal");
	v->c_re = v->mratio / 300;
	v->c_im = v->mratio / 300;
	while (++v->row < HEIGHT)
	{
		while (++v->col < WIDTH)
		{
			v->new_re = 1.5 * (v->col - (WIDTH / 2.0)) *
				(env->zoom / WIDTH) + env->ox;
			v->new_im = (v->row - (HEIGHT / 2.0)) *
				(env->zoom / HEIGHT) + env->oy;
			v->it = -1;
			while ((v->new_im * v->new_im + v->new_re * v->new_re) < 4
				&& ++v->it < env->it_max)
			{
				v->old_re = v->new_re;
				v->old_im = v->new_im;
				v->new_re = (v->old_re * v->old_re) -
					(v->old_im * v->old_im) + v->c_re;
				v->new_im = (2 * v->old_re * v->old_im) + v->c_im;
			}
			put_pxl(env, get_color(env, v->it), v->col, v->row);
		}
		v->col = 0;
	}
}

void				mandel_fractal(t_info *env, t_vars *v)
{
	env->frac_name = ft_strdup("Mandelbrot's Fractal");
	while (++v->row < HEIGHT)
	{
		while (++v->col < WIDTH)
		{
			v->c_re = (v->col - (WIDTH / 2.0)) * (env->zoom / WIDTH) + env->ox;
			v->c_im = (v->row - (HEIGHT / 2.0)) *
				(env->zoom / HEIGHT) + env->oy;
			v->x = 0;
			v->y = 0;
			v->it = 0;
			while ((v->x * v->x + v->y * v->y) < 4 && ++v->it < env->it_max)
			{
				v->new_re = (v->x * v->x) - (v->y * v->y) + v->c_re;
				v->y = 2 * v->x * v->y + v->c_im;
				v->x = v->new_re;
			}
			put_pxl(env, get_color(env, v->it), v->col, v->row);
		}
		v->col = 0;
	}
}

void				boat_fractal(t_info *env, t_vars *v)
{
	env->frac_name = ft_strdup("BurningShip's Fractal");
	while (++v->row < HEIGHT)
	{
		while (++v->col < WIDTH)
		{
			v->c_re = (v->col - (WIDTH / 2.0)) * (env->zoom / WIDTH) + env->ox;
			v->c_im = (v->row - (HEIGHT / 2.0)) *
				(env->zoom / HEIGHT) + env->oy;
			v->x = 0;
			v->y = 0;
			v->it = 0;
			while ((v->x * v->x + v->y * v->y) < 4 && ++v->it < env->it_max)
			{
				v->new_re = (fabs(v->x) * fabs(v->x)) - (fabs(v->y) *
														fabs(v->y)) + v->c_re;
				v->y = 2 * fabs(v->x) * fabs(v->y) + v->c_im;
				v->x = v->new_re;
			}
			put_pxl(env, get_color(env, v->it), v->col, v->row);
		}
		v->col = 0;
	}
}
