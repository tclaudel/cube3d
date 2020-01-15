/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:50:59 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:19:26 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void			ft_error(char *error)
{
	ft_dprintf(2, "\033[0;31m");
	ft_dprintf(2, "Error\n%s\n", error);
	dprintf(2, "\033[0m");
	while (1)
		;
	exit(0);
}
