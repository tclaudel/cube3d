/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 17:58:05 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static float	*ft_initvdir(t_cub *cub)
{
	float		*v_dir;

	v_dir = malloc(2 * sizeof(float));
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

static float	*ft_initplane(t_cub *cub)
{
	float		*plane;

	plane = malloc(2 * sizeof(float));
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

void	init_player(t_cub *cub)
{
	cub->pos_x = (float)cub->player[0];
	cub->pos_y = (float)cub->player[1];
	cub->v_dir = ft_initvdir(cub);
	cub->plane = ft_initplane(cub);
}
