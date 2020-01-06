/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 11:47:28 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static void		ft_initvdir(t_cub *cub)
{
	if (cub->orientation == 'E')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
	}
	if (cub->orientation == 'S')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
	}
	if (cub->orientation == 'N')
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
	cub->plane = malloc(sizeof(t_vector));
	if (cub->orientation == 'E')
	{
		cub->plane->x = 0;
		cub->plane->y = ((double)FOV / (double)100);
	}
	if (cub->orientation == 'N')
	{
		cub->plane->x = ((double)FOV / (double)100);
		cub->plane->y = 0;
	}
	if (cub->orientation == 'S')
	{
		cub->plane->x = -((double)FOV / (double)100);
		cub->plane->y = 0;
	}
	if (cub->orientation == 'W')
	{
		cub->plane->x = 0;
		cub->plane->y = -((double)FOV / (double)100);
	}
}

void			init_player(t_cub *cub)
{
	cub->pos = malloc(sizeof(t_vector));
	cub->pos->x = (double)cub->start->x + (double)0.5;
	cub->pos->y = (double)cub->start->y + (double)0.5;
	ft_initvdir(cub);
	ft_initplane(cub);
}
