/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:12 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/11 11:40:15 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			set_rgb(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

t_color				get_color(t_info *env, int it)
{
	t_color			color;

	(void)env;
	if ((it <= (env->it_max / 10)) && (it >= 0))
		set_rgb(&color, 30, 0, 0);
	else if ((it <= (env->it_max / 10) * 2) && it > (env->it_max / 10))
		set_rgb(&color, 50, 0, 10);
	else if ((it <= (env->it_max / 10) * 3) && it > (env->it_max / 10) * 2)
		set_rgb(&color, 70, 0, 15);
	else if ((it <= (env->it_max / 10) * 4) && it > (env->it_max / 10) * 3)
		set_rgb(&color, 100, 0, 20);
	else if ((it <= (env->it_max / 10) * 5) && it > (env->it_max / 10) * 4)
		set_rgb(&color, 150, 0, 25);
	else if ((it <= (env->it_max / 10) * 6) && it > (env->it_max / 10) * 5)
		set_rgb(&color, 180, 0, 30);
	else if ((it <= (env->it_max / 10) * 7) && it > (env->it_max / 10) * 6)
		set_rgb(&color, 210, 0, 40);
	else if ((it <= (env->it_max / 10) * 8) && it > (env->it_max / 10) * 7)
		set_rgb(&color, 240, 0, 50);
	else if ((it <= (env->it_max / 10) * 9) && it > (env->it_max / 10) * 8)
		set_rgb(&color, 255, 0, 80);
	else
		set_rgb(&color, 0, 0, 0);
	return (color);
}
