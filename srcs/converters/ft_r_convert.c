/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_r_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 15:01:59 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 10:47:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_r_convert(const char **token, t_cube3d *cub)
{
	int		nb;


	ft_dprintf(1, "CATCHING RESOLTUION\t| ");
	if(token[3])
		ft_error("too many arguments for this parameter");
	if (token[1] && token[2])
	{
		nb = ft_atoi(token[1]);
		if (nb > 5120 || nb <= 0)
			ft_error("problem with width detected");
		else
			cub->R[0] = nb;
		nb = ft_atoi(token[2]);
		if (nb > 2880 || nb <= 0)
			ft_error("problem with heigh detected");
		else
			cub->R[1] = nb;
	}
	else
		ft_error("need more arguments for resolution");
	ft_printfducul("res\t: %d * %d\n", cub->R[0], cub->R[1]);
}