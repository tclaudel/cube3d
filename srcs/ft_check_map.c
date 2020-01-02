/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:28:47 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 11:54:31 by tclaudel    ###    #+. /#+    ###.fr     */
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
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 255, 255, 0);
		else
			ft_dprintf(1, "\e[48;2;%d;%d;%dm  \e[0m", 255, 0, 0);
		i++;
	}
	ft_putchar('\n');
}

void			ft_check_map(int fd, char *line)
{
	t_map		*map;
	char		*strmap;
	size_t		i;

	i = 0;
	map = init_map();
	strmap = ft_calloc(1, 1);
	while (get_next_line(fd, &line))
	{
		if (line[0])
		{
			if (!(line[0] != '1' || line[0] != '\n'))
				ft_error("problem with map detected");
			strmap = ft_strfjoin(strmap, "\n", 1);
			strmap = ft_strfjoin(strmap, line, 2);
			map->height++;
		}
	}
	while (strmap[i++])
	{
		if (!ft_strchr("NSEW012\n \t", strmap[i]))
			ft_error("Wrong char in map");
	}
	ft_convert_map(strmap, map);
	ft_dprintf(1, "map size\t: %u * %u\n", map->width, map->height);
}
