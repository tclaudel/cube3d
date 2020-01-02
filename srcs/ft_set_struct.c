/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_struct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 13:52:47 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 17:58:54 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

// t_meta		*init_meta(void)
// {
// 	t_meta	*setup;

// 	if (!(setup = malloc(sizeof(t_meta))))
// 		ft_error("Malloc failed");
// 	setup->color = init_color();
// 	setup->map = init_map();
// 	setup->cub = init_cub3d();
// 	return (setup);
// }

t_cube3d	*init_cub3d(void)
{
	t_cube3d *setup;

	if (!(setup = malloc(sizeof(t_cube3d))))
		ft_error("Malloc failed");
	setup->r = malloc(2 * sizeof(int));
	setup->r[0] = -1;
	setup->r[1] = -1;
	setup->no = 0;
	setup->so = 0;
	setup->we = 0;
	setup->ea = 0;
	setup->s = 0;
	setup->f = -1;
	setup->c = -1;
	setup->camera_x = 0;
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

t_map		*init_map(void)
{
	t_map *setup;

	if (!(setup = malloc(sizeof(t_map))))
		ft_error("Malloc failed");
	setup->player = malloc(2 * sizeof(size_t));
	setup->orientation = 0;
	setup->width = 0;
	setup->height = 0;
	return (setup);
}
