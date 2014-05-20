/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 20:28:41 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 21:07:21 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_swapptr(t_pt **a, t_pt **b)
{
	t_pt	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_first_case(t_pt *a, t_pt *b, t_env *e)
{
	double	x;

	x = a->x_2d;
	while (x < b->x_2d)
	{
		ft_putpixel(x, a->y_2d + ((b->y_2d - a->y_2d) * (x - a->x_2d))
					/ (b->x_2d - a->x_2d), e);
		++x;
	}
}

static void	ft_draw_second_case(t_pt *a, t_pt *b, t_env *e)
{
	double	y;

	y = a->y_2d;
	while (y < b->y_2d)
	{
		ft_putpixel(a->x_2d + ((b->x_2d - a->x_2d) * (y - a->y_2d))
					/ (b->y_2d - a->y_2d), y, e);
		++y;
	}
}

void		ft_drawline(t_pt *a, t_pt *b, t_env *e)
{
	if (ABS(b->x_2d - a->x_2d) > ABS(b->y_2d - a->y_2d))
	{
		if (a->x_2d >= b->x_2d)
			ft_swapptr(&a, &b);
		ft_draw_first_case(a, b, e);
	}
	else
	{
		if (a->y_2d >= b->y_2d)
			ft_swapptr(&a, &b);
		ft_draw_second_case(a, b, e);
	}
}
