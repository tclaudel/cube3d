/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:33:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 13:02:17 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_cub(t_cub *cub)
{
	init_player(cub);
	//ft_load_textures(cub);
	ft_lunch_window(cub);
	return (1);
}
