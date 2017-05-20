/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:18:27 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/17 14:20:35 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void			reset(t_info *env)
{
	env->it_max = 30;
	env->lock = 0;
	env->ox = 0;
	env->oy = 0;
	env->zoom = 3;
	env->m_x = 1;
	env->m_y = 1;
	vars_init(env);
}

int					key_holder(int keycode, t_info *env)
{
	keycode == 34 ? reset(env) : 0;
	keycode == 53 ? exit(-1) : 0;
	keycode == 116 ? zoomed(env) : 0;
	keycode == 121 ? unzoomed(env) : 0;
	keycode == 123 ? env->ox += 0.1 : 0;
	keycode == 124 ? env->ox -= 0.1 : 0;
	keycode == 125 ? env->oy -= 0.1 : 0;
	keycode == 126 ? env->oy += 0.1 : 0;
	keycode == 78 && env->it_max > 0 ? env->it_max -= 10 : 0;
	keycode == 69 ? env->it_max += 10 : 0;
	if (keycode == 49)
		env->lock = (env->lock == 0) ? 1 : 0;
	return (1);
}

int					mouse_pos(int x, int y, t_info *env)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		env->m_x = x;
		env->m_y = y;
	}
	return (1);
}

int					mouse_holder(int keycode, int x, int y, t_info *env)
{
	(void)x;
	(void)y;
	keycode == 4 ? unzoomed(env) : 0;
	keycode == 5 ? zoomed(env) : 0;
	return (1);
}

void				core(t_info *env)
{
	mlx_hook(env->win, 2, (1L << 0), key_holder, env);
	mlx_hook(env->win, 6, (1L << 6), mouse_pos, env);
	mlx_mouse_hook(env->win, mouse_holder, env);
	mlx_expose_hook(env->win, tracing_main, env);
	mlx_loop_hook(env->mlx, refresher, env);
	mlx_loop(env->mlx);
}
