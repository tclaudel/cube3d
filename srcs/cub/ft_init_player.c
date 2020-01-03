/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 09:26:08 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static double	*ft_initvdir(t_cub *cub)
{
	double		*v_dir;

	v_dir = malloc(2 * sizeof(double));
	if (cub->orientation == 'N')
	{
		v_dir[0] = 0;
		v_dir[1] = 1;
	}
	if (cub->orientation == 'E')
	{
		v_dir[0] = 1;
		v_dir[1] = 0;
	}
	if (cub->orientation == 'S')
	{
		v_dir[0] = 0;
		v_dir[1] = -1;
	}
	if (cub->orientation == 'W')
	{
		v_dir[0] = -1;
		v_dir[1] = 0;
	}
	return (v_dir);
}

static double	*ft_initplane(t_cub *cub)
{
	double		*plane;

	plane = malloc(2 * sizeof(double));
	if (cub->orientation == 'N')
	{
		plane[0] = (FOV / 100);
		plane[1] = 0;
	}
	if (cub->orientation == 'E')
	{
		plane[0] = 0;
		plane[1] = -(FOV / 100);
	}
	if (cub->orientation == 'S')
	{
		plane[0] = -(FOV / 100);
		plane[1] = 0;
	}
	if (cub->orientation == 'W')
	{
		plane[0] = 0;
		plane[1] = (FOV / 100);
	}
	return (plane);
}

void			init_player(t_cub *cub)
{
	cub->player_pos = malloc(2 * sizeof(double));
	cub->player_pos[0] = (double)cub->player_start[0];
	cub->player_pos[1] = (double)cub->player_start[1];
	cub->player_dir = ft_initvdir(cub);
	cub->plane = ft_initplane(cub);
}
