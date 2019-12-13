/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_r_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 15:01:59 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:16:40 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_r1_convert(char **token, t_cube3d *cub)
{
	int		nb;

	nb = ft_atoi(token[2]);
	if (nb <= 0)
		ft_error("window's height can't be null");
	else if (nb > 1400)
		cub->r[1] = 1400;
	else
		cub->r[1] = nb;
}

void	ft_r_convert(char **token, t_cube3d *cub)
{
	int		nb;

	if (!(cub->r[0] != -1))
		ft_error("can't redefine parameter");
	ft_dprintf(1, "\nresolution\t: ");
	if (token[3])
		ft_error("too many arguments for this parameter");
	if (token[1] && token[2])
	{
		nb = ft_atoi(token[1]);
		if (nb <= 0)
			ft_error("window's width can't be null");
		else if (nb > 2560)
			cub->r[0] = 2560;
		else
			cub->r[0] = nb;
		ft_r1_convert(token, cub);
	}
	else
		ft_error("need more arguments for resolution");
	ft_printf("%d * %d\n", cub->r[0], cub->r[1]);
}
