/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 16:07:24 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:19:11 by tclaudel    ###    #+. /#+    ###.fr     */
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
		free(c->start);

}

int				ft_close(t_cub *c)
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
	exit(EXIT_SUCCESS);
}