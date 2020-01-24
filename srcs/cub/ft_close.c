/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 16:07:24 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 09:56:07 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_free_path(t_cub *c)
{
	ft_strdel(&c->no);
	ft_strdel(&c->so);
	ft_strdel(&c->we);
	ft_strdel(&c->ea);
	ft_strdel(&c->s);
	free(c->res);
	free(c->sprites);
	free(c->color);
}

int				ft_close(t_cub *c, int ret_exit)
{
	size_t	i;

	i = 0;
	ft_free_path(c);
	if (c->flag == 'e')
		ft_save_map(c);
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
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
