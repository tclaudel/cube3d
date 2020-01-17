/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_r_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 15:01:59 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 09:13:26 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_r1_convert(char **token, t_cub *cub)
{
	int		nb;

	nb = ft_atoi(token[2]);
	if (nb <= 0)
		ft_error("window's height can't be null");
	else if (nb > 1400)
		cub->res[1] = 1400;
	else
		cub->res[1] = nb;
}

void	ft_r_convert(char **token, t_cub *cub)
{
	int		nb;

	if (cub->res[0] != -1 && cub->res[1] != -1)
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
			cub->res[0] = 2560;
		else
			cub->res[0] = nb;
		ft_r1_convert(token, cub);
	}
	else
		ft_error("need more arguments for resolution");
	if (cub->res[1] < 300)
		cub->res[1] = 300;
	if (cub->res[0] < cub->res[1])
		cub->res[0] = cub->res[1];
	ft_printf("%d * %d\n", cub->res[0], cub->res[1]);
}
