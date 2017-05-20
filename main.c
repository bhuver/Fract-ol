/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhuver <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:03:11 by bhuver            #+#    #+#             */
/*   Updated: 2016/10/11 11:38:13 by bhuver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init(t_info **env, char frac)
{
	(*env)->it_max = 30;
	(*env)->lock = 0;
	(*env)->ox = 0;
	(*env)->oy = 0;
	(*env)->zoom = (frac == 'J') ? 2 : 3;
	(*env)->m_x = 1;
	(*env)->m_y = 1;
	(*env)->img = mlx_new_image((*env)->mlx, WIDTH, HEIGHT);
	(*env)->img_ptr = mlx_get_data_addr((*env)->img, &((*env)->bpp),
										&((*env)->sl), &((*env)->endian));
	(*env)->win = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!(*env)->win)
		exit(-1);
}

static void		start_fractol(char *frac)
{
	t_info		*info;
	t_vars		vars;

	if (!(info = malloc(sizeof(t_info))))
		exit(1);
	info->frac_ptr = (frac[0] == 'J' ? &(julia_fractal) : 0);
	info->frac_ptr = (frac[0] == 'M' ? &(mandel_fractal) : info->frac_ptr);
	info->frac_ptr = (frac[0] == 'B' ? &(boat_fractal) : info->frac_ptr);
	if (!info->frac_ptr || frac[1])
	{
		free(info);
		ft_putendl_fd("Error params.\nUse: ./fractol [J | M | B]", 2);
		exit(-1);
	}
	info->mlx = mlx_init();
	init(&info, frac[0]);
	info->v = &vars;
	core(info);
	free(info);
}

int				main(int ac, char **av)
{
	if (ac == 2)
		start_fractol(av[1]);
	else
		ft_putendl("Use:\n./fractol [J | M | B]");
	return (0);
}
