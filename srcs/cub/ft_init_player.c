/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:53:42 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 14:00:23 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static float	*ft_initvdir(t_map *map)
{
	float		*v_dir;

	v_dir = malloc(2 * sizeof(float));
	if (map->orientation == 'N')
	{
		v_dir[0] = 0;
		v_dir[0] = 1;
	}
	if (map->orientation == 'E')
	{
		v_dir[0] = 1;
		v_dir[0] = 0;
	}
	if (map->orientation == 'S')
	{
		v_dir[0] = 0;
		v_dir[0] = -1;
	}
	if (map->orientation == 'W')
	{
		v_dir[0] = -1;
		v_dir[0] = 0;
	}
	return (v_dir);
}

t_player		*init_player(t_map *map)
{
	t_player	*setup;

	if (!(setup = malloc(sizeof(t_player))))
		ft_error("Malloc failed");
	setup->pos_x = (float)map->player[0];
	setup->pos_y = (float)map->player[0];
	setup->v_dir = ft_initvdir(map);
	return (setup);
}
