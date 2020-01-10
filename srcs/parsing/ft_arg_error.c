/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 12:57:13 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:29:35 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_arg_error(char *av)
{
	const char	*error;

	error = ft_strrchr(av, '.');
	if (ft_strncmp(".cub", error, 4))
		ft_error("Wrong map extension, should be .cub");
}
