/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 09:28:16 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 11:36:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static int		ft_all_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_set_color(char *token)
{
	int		color;

	color = ft_atoi(token);
	if (color < 0 || color > 255)
		ft_error("Problem with color detected");
	return (color);
}

static void		ft_tok(char **token, t_cub *cub)
{
	if (token[4])
		ft_error("too mant arguments");
	if (ft_all_digit(token[1]))
		cub->color->rgb.r = ft_set_color(token[1]);
	else
		ft_error("not a valid nomber");
	if (ft_all_digit(token[2]))
		cub->color->rgb.g = ft_set_color(token[2]);
	else
		ft_error("not a valid nomber");
	if (ft_all_digit(token[3]))
		cub->color->rgb.b = ft_set_color(token[3]);
	else
		ft_error("not a valid nomber");
	cub->c = cub->color->color;
}

void			ft_c_convert(char **token, t_cub *cub)
{
	if ((cub->c != -1))
		ft_error("can't redefine parameter");
	ft_dprintf(1, "ceiling color\t: ");
	if (token[1] && token[2] && token[3])
		ft_tok(token, cub);
	else
		ft_error("problem with args for color");
	ft_dprintf(1, "\e[48;2;%d;%d;%dm     \e[0m",
		cub->color->rgb.r, cub->color->rgb.g, cub->color->rgb.b);
	ft_dprintf(1, "\tR: %d, G: %d, B: %d\n",
		cub->color->rgb.r, cub->color->rgb.g, cub->color->rgb.b);
}
