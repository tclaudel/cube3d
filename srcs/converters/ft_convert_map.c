/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:09:10 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 11:59:40 by tclaudel    ###    #+. /#+    ###.fr     */
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

void	ft_check_walls(t_cub *cub)
{
	size_t	i;

	i = 0;
	while (i < cub->map_width - 1)
	{
		if (cub->map[0][i] != '1' || cub->map[cub->map_height - 1][i] != '1')
			ft_error("cub isn't closed");
		i++;
	}
	i = 0;
	while (i < cub->map_height)
	{
		if (cub->map[i][0] != '1' || cub->map[i][cub->map_width - 1] != '1')
			ft_error("cub isn't closed");
		i++;
	}
	ft_printf("\n\ncheck wall\t: [OK]\n");
}

void	set_player(t_cub *cub, size_t i, size_t j, char c)
{
	if (!cub->orientation)
	{
		cub->start->x = i;
		cub->start->y = j;
		cub->orientation = c;
	}
	else
		ft_error("2 players detected");
}

void	ft_pos(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < cub->map_height)
	{
		i = 0;
		while (i < cub->map_width)
		{
			if (ft_strchr("NSEW", cub->map[j][i]))
				set_player(cub, i, j, cub->map[j][i]);
			i++;
		}
		j++;
	}
	ft_printf("player\t\t: X = %u  Y = %u  oriented : %c\n",
		cub->start->x, cub->start->y, cub->orientation);
}

void	ft_convert_map(char *strcub, t_cub *cub)
{
	char	*tmp;
	size_t	i;

	i = 1;
	cub->map = malloc(sizeof(char *) * cub->map_height);
	tmp = ft_strtok(strcub, "\n");
	cub->map[0] = ft_stroutcharset(tmp, " ");
	cub->map_width = ft_strlen(cub->map[0]);
	while ((tmp = ft_strtok(NULL, "\n")))
	{
		tmp = ft_stroutcharset(tmp, " ");
		if (ft_strlen(tmp) != cub->map_width)
			ft_error("problem with cub size");
		cub->map[i] = tmp;
		i++;
	}
	i = 0;
	while (i < cub->map_height)
		ft_str_convert(cub->map[i++]);
	ft_check_walls(cub);
	ft_pos(cub);
}
