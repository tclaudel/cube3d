/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 16:07:24 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:16:28 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_free_path(t_cub *c)
{
		free(c->no);
		free(c->so);
		free(c->we);
		free(c->ea);
		free(c->s);
		free(c->res);
		free(c->sprites);
		free(c->color);
}

int				ft_close(t_cub *c, int ret_exit)
{
	size_t	i;

	i = 0;
	ft_free_path(c);
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	while (i < c->map_height)
	{
		free(c->tabmap[i]);
		i++;
	}
	free(c->tabmap);
	free(c->zbuffer);
	free(c);
	while (1)
		;
	exit(ret_exit);
}

void			ft_exit_load(t_cub *c)
{
	size_t	i;

	i = 0;
	ft_dprintf(2, "\033[0;31m");
	ft_dprintf(2, "Error\n%s\n", "Failed to load textures");
	dprintf(2, "\033[0m");
	ft_free_path(c);
	while (i < c->map_height)
	{
		free(c->tabmap[i]);
		i++;
	}
	free(c->tabmap);
	free(c);
	exit(EXIT_FAILURE);
}

void			ft_next_level(t_cub *c)
{
	size_t	i;
	char **next;

	i = 0;
	next = (char **)malloc(sizeof(char *) * 2);
	next[0] = ft_strdup("./cub3d");
	next[1] = ft_strdup("map2.cub");
	ft_free_path(c);
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	while (i < c->map_height)
	{
		free(c->tabmap[i]);
		i++;
	}
	free(c->tabmap);
	free(c->zbuffer);
	free(c);
	ft_start(2, next, 1);
}
