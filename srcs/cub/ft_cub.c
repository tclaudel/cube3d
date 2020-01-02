/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:33:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 17:21:56 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_cub(t_meta *meta)
{
	meta->player = init_player(meta->map);
	ft_lunch_window(meta);
	return (1);
}
