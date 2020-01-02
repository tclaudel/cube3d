/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 15:16:01 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"
#include "config.h"

static float	*ft_initvdir(t_map *map)
{
	float		*v_dir;

	v_dir = malloc(2 * sizeof(float));
	if (map->orientation == 'N')
	{
		v_dir[0] = 0;
		v_dir[1] = 1;
	}
	if (map->orientation == 'E')
	{
		v_dir[0] = 1;
		v_dir[1] = 0;
	}
	if (map->orientation == 'S')
	{
		v_dir[0] = 0;
		v_dir[1] = -1;
	}
	if (map->orientation == 'W')
	{
		v_dir[0] = -1;
		v_dir[1] = 0;
	}
	return (v_dir);
}

static float	*ft_initplane(t_map *map)
{
	float		*plane;

	plane = malloc(2 * sizeof(float));
	if (map->orientation == 'N')
	{
		plane[0] = (FOV / 100);
		plane[1] = 0;
	}
	if (map->orientation == 'E')
	{
		plane[0] = 0;
		plane[1] = -(FOV / 100);
	}
	if (map->orientation == 'S')
	{
		plane[0] = -(FOV / 100);
		plane[1] = 0;
	}
	if (map->orientation == 'W')
	{
		plane[0] = 0;
		plane[1] = (FOV  / 100);
	}
	return (plane);
}

t_player		*init_player(t_map *map)
{
	t_player *setup;

	if (!(setup = malloc(sizeof(t_player))))
		ft_error("Malloc failed");
	setup->pos_x = (float)map->player[0];
	setup->pos_y = (float)map->player[0];
	setup->v_dir = ft_initvdir(map);
	setup->plane = ft_initplane(map);
	return (setup);
}
