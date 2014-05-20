/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 20:21:36 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 21:09:10 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

static void		ft_colorchoice(t_env *e, int keycode)
{
	if (keycode == 32 || keycode == 100)
	{
		e->r = 0xcc;
		e->g = 0xcc;
		e->b = 0xcc;
	}
	if (keycode == 114 && (e->r = 0xcc))
	{
		e->g = 0;
		e->b = 0;
	}
	if (keycode == 103 && (e->g = 0xcc))
	{
		e->r = 0x42;
		e->b = 0x42;
	}
	if (keycode == 98 && (e->b = 0xe9))
	{
		e->r = 0x42;
		e->g = 0xaa;
	}
	ft_draw(e);
}

int				ft_exposehook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int				ft_keypress(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 32)
	{
		e->zoom = 10;
		ft_colorchoice(e, keycode);
	}
	e->zoom = (keycode == 65453) ? e->zoom * 0.85 : e->zoom;
	e->zoom = (keycode == 65451) ? e->zoom / 0.85 : e->zoom;
	e->zoom = (e->zoom <= 0) ? 0.1337 : e->zoom;
	if (keycode == 114 || keycode == 103 || keycode == 98 || keycode == 100)
		ft_colorchoice(e, keycode);
	ft_draw(e);
	return (0);
}

int				ft_mousehook(int keycode, int x, int y, t_env *e)
{
	int			i;
	int			j;
	double		mult;

	x += y;
	mult = 1;
	mult = (keycode == 5) ? 0.97 : mult;
	mult = (keycode == 4) ? 1.03 : mult;
	if (mult != 1)
	{
		j = -1;
		while (++j < e->height && (i = -1))
			while (++i < e->width)
			{
				if (e->grid[j][i].z != 0)
					e->grid[j][i].z *= mult;
			}
		ft_draw(e);
	}
	return (0);
}
