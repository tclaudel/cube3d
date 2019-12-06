/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 15:35:45 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 08:21:19 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_convert_line(char *line, t_cube3d *pf)
{
	char *token;

	ft_dprintf(1, "prout");
	token = ft_strtok(line, " ");
	pf->NO = "prout";

	dprintf(1, "tokem\t: %s\n", token);

	return(1);
}