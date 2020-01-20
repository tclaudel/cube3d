/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 16:07:24 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 13:22:59 by tclaudel    ###    #+. /#+    ###.fr     */
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
	ft_save_map(c);
	while (i < c->map_height)
	{
		free(c->tabmap[i]);
		i++;
	}
	free(c->tabmap);
	free(c->zbuffer);
	free(c);
	exit(ret_exit);
}

void			ft_exit_load(t_cub *c)
{
	size_t	i;

	i = 0;
	ft_dprintf(2, "\033[0;31m");
	ft_dprintf(2, "Error\n%s\n", "Failed to load textures");
	ft_dprintf(2, "\033[0m");
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

static char		**ft_select_level(char level, int *vic)
{
	char	**next;

	next = (char **)malloc(sizeof(char *) * 2);
	next[0] = ft_strdup("./cub3d");
	if (level == 1)
		next[1] = ft_strdup("map2.cub");
	else if (level == 2)
		next[1] = ft_strdup("mapmhaman.cub");
	else
	{
		*vic = 1;
		next[1] = ft_strdup("mapmhaman.cub");
	}
	return (next);
}

void			ft_next_level(t_cub *c)
{
	size_t			i;
	char			**next;
	int				victory;
	static char		level = 0;

	i = 0;
	victory = 0;
	level++;
	next = ft_select_level(level, &victory);
	ft_free_path(c);
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	while (i < c->map_height)
	{
		free(c->tabmap[i]);
		i++;
	}
	free(c->tabmap);
	free(c->zbuffer);
	ft_start(2, next, 1 + victory);
}
