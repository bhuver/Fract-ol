/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:48:12 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/11 11:47:05 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					put_pxl(t_info *env, t_color color, int x, int y)
{
	int				r;

	color.r += 0;
	r = (x * env->bpp / 8) + (y * env->sl);
	if ((x < WIDTH && y < HEIGHT && x >= 0 && y >= 0))
	{
		(env->img_ptr)[r++] = !env->endian ? color.b : color.r;
		(env->img_ptr)[r++] = !env->endian ? color.g : color.b;
		(env->img_ptr)[r] = !env->endian ? color.r : color.g;
	}
	return (1);
}

static void			clear_img(t_info *env)
{
	int				a[2];
	t_color			mc;

	mc.r = 0;
	mc.g = 0;
	mc.b = 0;
	a[0] = -1;
	while (++a[0] < WIDTH && (a[1] = -1) < 0)
		while (++a[1] < HEIGHT)
			put_pxl(env, mc, a[0], a[1]);
}

int					refresher(t_info *env)
{
	clear_img(env);
	tracing_main(env);
	return (1);
}

int					tracing_main(t_info *env)
{
	char			*it;

	vars_init(env);
	env->frac_ptr(env, env->v);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, env->frac_name);
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, "Iterations: ");
	it = ft_itoa(env->it_max);
	mlx_string_put(env->mlx, env->win, 150, 40, 0xFFFFFF, it);
	free(env->frac_name);
	free(it);
	return (1);
}
