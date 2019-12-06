/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:57:13 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 15:20:49 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_arg_error(int ac __attribute__ ((unused)), char *av __attribute__ ((unused)))
{
	const char	*error;

	if (ac == 1)
	{
		ft_error("No map founded");
		exit(0);
	}
	else if (ac > 2)
	{
		ft_error("Too many arguments");
		exit(0);
	}
	error = ft_strrchr(av, '.');
	if (ft_strncmp(".cub", error, 4))
	{
		ft_error("Wrong extension");
		exit(0);
	}
}