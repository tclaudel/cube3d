/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_struct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:52:47 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 17:15:28 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

t_cub		*init_cub(void)
{
	t_cub *setup;

	if (!(setup = malloc(sizeof(t_cub))))
		ft_error("Malloc failed");
	setup->res = malloc(2 * sizeof(int));
	setup->res[0] = -1;
	setup->res[1] = -1;
	setup->no = 0;
	setup->so = 0;
	setup->we = 0;
	setup->ea = 0;
	setup->s = 0;
	setup->f = -1;
	setup->c = -1;
	setup->camera_x = 0;
	setup->color = init_color();
	return (setup);
}

t_color		*init_color(void)
{
	t_color *setup;

	if (!(setup = malloc(sizeof(t_color))))
		ft_error("Malloc failed");
	setup->color = 0;
	setup->rgb.a = 0;
	setup->rgb.b = 0;
	setup->rgb.r = 0;
	setup->rgb.g = 0;
	return (setup);
}

void		init_map(t_cub *setup)
{
	setup->square = malloc(sizeof(t_pos));
	setup->step = malloc(sizeof(t_pos));
	setup->start = malloc(sizeof(t_vector));
	setup->orientation = 0;
	setup->map_width = 0;
	setup->map_height = 0;
}
