/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 20:23:32 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 21:10:01 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		ft_putpixel(int x, int y, t_env *e)
{
	x += (WIDTH / 2) - SHIFT;
	y += (HEIGHT / 2) - SHIFT;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	e->table[(y * e->size) + (x * (e->bpp / 8)) + 0] = e->b;
	e->table[(y * e->size) + (x * (e->bpp / 8)) + 1] = e->g;
	e->table[(y * e->size) + (x * (e->bpp / 8)) + 2] = e->r;
}

void		ft_center(t_env *e, float x_shift, float y_shift, float z_shift)
{
	int		i;
	int		j;

	j = -1;
	x_shift = e->width / 2;
	y_shift = e->height / 2;
	while (++j < e->height && (i = -1))
		while (++i < e->width)
		{
			e->z_min = (e->grid[j][i].z < e->z_min)
				? e->grid[j][i].z : e->z_min;
			e->z_max = (e->grid[j][i].z > e->z_max)
				? e->grid[j][i].z : e->z_max;
		}
	j = -1;
	z_shift = (e->z_max + e->z_min) / 2;
	while (++j < e->height && (i = -1))
		while (++i < e->width)
		{
			e->grid[j][i].x = i - x_shift;
			e->grid[j][i].y = j - y_shift;
			e->grid[j][i].z -= z_shift;
		}
}

static void	ft_fillimg(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = e->size * HEIGHT;
	while (++i < j)
		e->table[i] = 0x39;
}

static void	ft_transform(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (++j < e->height && (i = -1))
		while (++i < e->width)
		{
			e->grid[j][i].x_2d = (e->grid[j][i].x * e->zoom) + SHIFT;
			e->grid[j][i].x_2d -= e->grid[j][i].y * e->zoom;
			e->grid[j][i].y_2d = -0.15 * e->grid[j][i].z * e->zoom;
			e->grid[j][i].y_2d += (e->grid[j][i].x * e->zoom) + SHIFT;
			e->grid[j][i].y_2d += e->grid[j][i].y * e->zoom;
		}
}

void		ft_draw(t_env *e)
{
	int		i;
	int		j;

	ft_fillimg(e);
	ft_transform(e);
	i = -1;
	while (++i < e->height && (j = -1))
		while (++j < (e->width - 1))
			ft_drawline(&e->grid[i][j], &e->grid[i][j + 1], e);
	i = -1;
	while (++i < (e->height - 1) && (j = -1))
		while (++j < e->width)
			ft_drawline(&e->grid[i][j], &e->grid[i + 1][j], e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
