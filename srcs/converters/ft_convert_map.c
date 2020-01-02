/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:09:10 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 11:36:10 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_stroutcharset(char *str, char *charset)
{
	size_t	lmalloc;
	size_t	i;
	size_t	j;
	char	*ret;

	lmalloc = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			lmalloc++;
		i++;
	}
	ret = malloc((sizeof(char) * lmalloc + 1));
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			ret[j++] = str[i];
		i++;
	}
	ret[lmalloc] = 0;
	return (ret);
}

void	ft_check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->width - 1)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			ft_error("map isn't closed");
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			ft_error("map isn't closed");
		i++;
	}
	ft_printf("\n\ncheck wall\t: [OK]\n");
}

void	set_player(t_map *map, size_t i, size_t j, char c)
{
	if (!map->orientation)
	{
		map->player[0] = i;
		map->player[1] = j;
		map->orientation = c;
	}
	else
		ft_error("2 players detected");
}

void	ft_player_pos(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (ft_strchr("NSEW", map->map[j][i]))
				set_player(map, i, j, map->map[j][i]);
			i++;
		}
		j++;
	}
	ft_printf("player\t\t: X = %u  Y = %u  oriented : %c\n",
		map->player[0], map->player[1], map->orientation);
}

char	**ft_convert_map(char *strmap, t_map *map)
{
	char	*tmp;
	size_t	i;

	i = 1;
	map->map = malloc(sizeof(char *) * map->height);
	tmp = ft_strtok(strmap, "\n");
	map->map[0] = ft_stroutcharset(tmp, " ");
	map->width = ft_strlen(map->map[0]);
	while ((tmp = ft_strtok(NULL, "\n")))
	{
		tmp = ft_stroutcharset(tmp, " ");
		if (ft_strlen(tmp) != map->width)
			ft_error("problem with map size");
		map->map[i] = tmp;
		i++;
	}
	i = 0;
	while (i < map->height)
		ft_str_convert(map->map[i++]);
	ft_check_walls(map);
	ft_player_pos(map);
	return (map->map);
}
