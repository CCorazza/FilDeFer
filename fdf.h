/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 20:33:16 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 21:09:33 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define WIDTH (2100)
# define HEIGHT (1050)
# define SHIFT (5000)
# define ABS(a) ((a < 0) ? (-(a)) : (a))

# include <string.h>

typedef struct		s_pt
{
	double			x;
	double			y;
	double			z;
	double			x_2d;
	double			y_2d;
}					t_pt;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_pt			**grid;
	char			*table;
	int				width;
	int				height;
	int				bpp;
	int				size;
	int				endian;
	int				z_min;
	int				z_max;
	double			zoom;
	int				r;
	int				g;
	int				b;
}					t_env;

void				*ft_xmalloc(size_t size);
void				ft_error(char *s);

void				ft_center(t_env *e, float x_shift, float y_shift,
															float z_shift);
void				ft_draw(t_env *e);
void				ft_putpixel(int x, int y, t_env *e);
void				ft_drawline(t_pt *a, t_pt *b, t_env *e);

int					ft_exposehook(t_env *e);
int					ft_keypress(int keycode, t_env *e);
int					ft_mousehook(int keycode, int x, int y, t_env *e);

#endif