/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 13:37:12 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static void		ft_initvdir(t_cub *cub)
{
	if (cub->orientation == 'N')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
	}
	if (cub->orientation == 'E')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
	}
	if (cub->orientation == 'S')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
	}
	if (cub->orientation == 'W')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
	}
}

static void		ft_initplane(t_cub *cub)
{
	if (cub->orientation == 'N')
	{
		cub->plane.x = (FOV / 100);
		cub->plane.y = 0;
	}
	if (cub->orientation == 'E')
	{
		cub->plane.x = 0;
		cub->plane.y = -(FOV / 100);
	}
	if (cub->orientation == 'S')
	{
		cub->plane.x = -(FOV / 100);
		cub->plane.y = 0;
	}
	if (cub->orientation == 'W')
	{
		cub->plane.x = 0;
		cub->plane.y = (FOV / 100);
	}
}

void			init_player(t_cub *cub)
{
	cub->pos = malloc(sizeof(t_vector));
	cub->pos->x = cub->start->x;
	cub->pos->y = cub->start->y;
	ft_initvdir(cub);
	ft_initplane(cub);
}
