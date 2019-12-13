/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_struct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 09:51:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:25:34 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

t_meta		*set_meta(void)
{
	t_meta	*setup;

	if (!(setup = malloc(sizeof(t_meta))))
		ft_error("Malloc failed");
	setup->color = set_color();
	setup->map = set_map();
	setup->cub = set_cub3d();
	return (setup);
}

t_cube3d	*set_cub3d(void)
{
	t_cube3d *setup;

	if (!(setup = malloc(sizeof(t_cube3d))))
		ft_error("Malloc failed");
	setup->r = malloc(2 * sizeof(int));
	setup->no = 0;
	setup->so = 0;
	setup->we = 0;
	setup->ea = 0;
	setup->s = 0;
	setup->f = -1;
	setup->c = -1;
	return (setup);
}

t_color		*set_color(void)
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

t_map		*set_map(void)
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
