/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 09:55:22 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static void		ft_initvdir(t_cub *cub)
{
	if (cub->orientation == 'N')
	{
		cub->player_dir.x = 0;
		cub->player_dir.y = 1;
	}
	if (cub->orientation == 'E')
	{
		cub->player_dir.x = 1;
		cub->player_dir.y = 0;
	}
	if (cub->orientation == 'S')
	{
		cub->player_dir.x = 0;
		cub->player_dir.y = -1;
	}
	if (cub->orientation == 'W')
	{
		cub->player_dir.x = -1;
		cub->player_dir.y = 0;
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
	cub->player_pos = malloc(2 * sizeof(double));
	cub->player_pos[0] = (double)cub->player_start[0];
	cub->player_pos[1] = (double)cub->player_start[1];
	ft_initvdir(cub);
	ft_initplane(cub);
}
