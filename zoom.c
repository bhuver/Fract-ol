/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:30:31 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/17 14:14:17 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoomed(t_info *env)
{
	double pas[2];
	double dmsx;
	double dmsy;
	double ds;
	double hw[2];

	ds = 320;
	hw[0] = (double)HEIGHT / 2;
	hw[1] = (double)WIDTH / 2;
	dmsx = fabs(env->m_x - hw[1]);
	dmsy = fabs(env->m_y - hw[0]);
	env->zoom *= 0.9;
	pas[0] = (0.03 / env->zoom) * (0.01 * dmsx);
	pas[1] = (0.03 / env->zoom) * (0.01 * dmsy);
	if (env->m_x > 0 && env->m_x < hw[1])
		env->ox -= pas[0];
	if (env->m_x > hw[1])
		env->ox += pas[0];
	if (env->m_y > 0 && env->m_y < hw[0])
		env->oy -= pas[1];
	if (env->m_y > hw[0])
		env->oy += pas[1];
}

void				unzoomed(t_info *env)
{
	double pas[2];
	double dmsx;
	double dmsy;
	double ds;
	double hw[2];

	ds = 320;
	hw[0] = HEIGHT / 2;
	hw[1] = WIDTH / 2;
	dmsx = fabs(env->m_x - hw[1]);
	dmsy = fabs(env->m_y - hw[0]);
	env->zoom *= 1.1;
	pas[0] = (0.03 / env->zoom) * (0.01 * dmsx);
	pas[1] = (0.03 / env->zoom) * (0.01 * dmsy);
	if (env->m_x > 0 && env->m_x < hw[1])
		env->ox -= pas[0];
	if (env->m_x > hw[1])
		env->ox += pas[0];
	if (env->m_y > 0 && env->m_y < hw[0])
		env->oy -= pas[1];
	if (env->m_y > hw[0])
		env->oy += pas[1];
}
