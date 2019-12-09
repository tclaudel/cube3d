/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:57:13 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:27:11 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_arg_error(int ac, char *av)
{
	const char	*error;

	if (ac == 1)
		ft_error("No map founded");
	else if (ac > 2)
		ft_error("Too many arguments");
	error = ft_strrchr(av, '.');
	if (ft_strncmp(".cub", error, 4))
		ft_error("Wrong map extension, should be .cub");
}
