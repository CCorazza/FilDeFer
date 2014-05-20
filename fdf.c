/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 02:55:36 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 21:12:12 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include "fdf.h"
#include "get_next_line.h"

static t_pt	**ft_addline(t_pt **grid, char **tab, t_env *e)
{
	int		i;
	int		j;
	t_pt	**ret;

	i = 0;
	while (grid[i])
		++i;
	ret = (t_pt**)ft_xmalloc(sizeof(t_pt*) * (i + 2));
	i = -1;
	while (grid[++i])
		ret[i] = grid[i];
	free(grid);
	j = 0;
	while (tab[j])
		++j;
	e->width = (j < e->width) ? j : e->width;
	ret[i] = (t_pt*)ft_xmalloc(sizeof(t_pt) * j);
	j = -1;
	e->z_min = ft_atoi(tab[0]);
	e->z_max = ft_atoi(tab[0]);
	while (tab[++j])
		ret[i][j].z = ft_atoi(tab[j]);
	ret[++i] = NULL;
	return (ret);
}

static void	ft_getinput(t_env *e, char *av)
{
	int		j;
	int		fd;
	char	*s;
	char	**tab;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("open: Le fichier n'a pas ete lu.");
	e->height = 0;
	e->width = 0x0FFFFFFF;
	e->grid = (t_pt**)ft_xmalloc(sizeof(t_pt*));
	e->grid[0] = NULL;
	while (get_next_line(fd, &s) > 0 && ++(e->height))
	{
		if (!(tab = ft_strsplit(s, ' ')))
			ft_error("ft_strsplit: La ligne ne peut pas etre splittee.");
		e->grid = ft_addline(e->grid, tab, e);
		free(s);
		j = 0;
		while (tab[j])
			free(tab[j++]);
		free(tab);
	}
	close(fd);
}

void		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void		*ft_xmalloc(size_t size)
{
	void	*res;

	if ((res = (void*)malloc(size)) == NULL)
		ft_error("malloc: Impossible d'allouer la memoire.");
	return (res);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("Voir Usage a la compilation.");
	ft_getinput(&e, av[1]);
	if (!(e.mlx = mlx_init()))
		ft_error("mlx_init: Connexion au Xserver echouee.");
	if (!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fdf")))
		ft_error("mlx_new_window: La fenetre n'a pas pu etre creee.");
	if (!(e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
		ft_error("mlx_new_image: L'image n'a pas pu etre creee.");
	if (!(e.table = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian)))
		ft_error("mlx_get_data_addr: Les donnees n'ont pas pu etre lues.");
	e.zoom = 10;
	e.r = 0xcc;
	e.g = 0xcc;
	e.b = 0xcc;
	ft_center(&e, 0, 0, 0);
	ft_draw(&e);
	mlx_expose_hook(e.win, &ft_exposehook, &e);
	mlx_mouse_hook(e.win, &ft_mousehook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, &ft_keypress, &e);
	mlx_loop(e.mlx);
	return (0);
}
