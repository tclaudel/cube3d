/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:28:47 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 10:50:33 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void			ft_str_convert(char *str)
{
	size_t	i;

	i = 0;
	ft_putchar('\t');
	while (str[i])
	{
		if (str[i] == '0')
			ft_putstr("  ");
		else if (str[i] == '1')
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 255, 255, 255);
		else if (str[i] == '2')
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 50, 50, 50);
		else if (str[i] == '3')
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 0, 255, 0);
		else if (str[i] == '4')
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 255, 0, 0);
		else if (str[i] == '5')
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 230, 230, 230);
		else
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 51, 51, 255);
		i++;
	}
	ft_putchar('\n');
}

void			ft_check_map(int fd, char *line, t_cub *cub)
{
	char		*strmap;
	size_t		i;

	i = 0;
	init_map(cub);
	strmap = ft_calloc(1, 1);
	while (get_next_line(fd, &line))
	{
		if (line[0])
		{
			if (!(line[0] != '1' || line[0] != '\n'))
				ft_error("problem with map detected");
			strmap = ft_strfjoin(strmap, "\n", 1);
			strmap = ft_strfjoin(strmap, line, 3);
			cub->map_height++;
		}
		else
			free(line);
	}
	while (strmap[i++])
	{
		if (!ft_strchr("NSEW012345\n \t", strmap[i]))
			ft_error("Wrong char in map");
	}
	ft_convert_map(strmap, cub);
}
