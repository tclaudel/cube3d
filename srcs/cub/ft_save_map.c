/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 16:48:46 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 16:53:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_save_map(t_cub *c)
{
	int		fd;
	size_t	i;

	i = 0;
	if (!(fd = open("edited_map.cub", O_RDWR)))
	{
		ft_dprintf(2, "can't save map\n");
		c->flag = 0;
	}
	mlx_destroy_window(c->mlx_ptr, c->mlx_win);
	if (c->flag == 'e')
	{
		ft_printf("\nHere is your edited map :\n\n");
		while (i < c->map_height)
		{
			ft_printf("%s\n", c->tabmap[i]);
			ft_dprintf(fd, "%s\n", c->tabmap[i]);
			i++;
		}
	}
	close(fd);
}
