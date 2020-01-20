/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:09:10 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 10:53:36 by tclaudel    ###    #+. /#+    ###.fr     */
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
		if (cub->tabmap[0][i] != '1' ||
			cub->tabmap[cub->map_height - 1][i] != '1')
			ft_error("cub isn't closed");
		i++;
	}
	i = 0;
	while (i < cub->map_height)
	{
		if (cub->tabmap[i][0] != '1' ||
			cub->tabmap[i][cub->map_width - 1] != '1')
			ft_error("cub isn't closed");
		i++;
	}
	ft_printf("\n\ncheck wall\t: [OK]\n");
}

void	set_player(t_cub *cub, size_t i, size_t j, char c)
{
	if (!cub->orientation)
	{
		cub->map.x = j;
		cub->map.y = i;
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
			if (ft_strchr("NSEW", cub->tabmap[j][i]))
			{
				set_player(cub, i, j, cub->tabmap[j][i]);
				cub->tabmap[j][i] = '0';
			}
			i++;
		}
		j++;
	}
	if (cub->map.x == 0)
		ft_error("Can't find a player");
	ft_printf("player\t\t: X = %u  Y = %u  oriented : %c\n",
		cub->map.x, cub->map.y, cub->orientation);
}

void	ft_convert_map(char *strcub, t_cub *cub)
{
	char	*tmap;
	size_t	i;

	i = 1;
	cub->tabmap = malloc(sizeof(char *) * cub->map_height);
	tmap = ft_strtok(strcub, "\n");
	cub->tabmap[0] = ft_stroutcharset(tmap, " \t");
	cub->map_width = ft_strlen(cub->tabmap[0]);
	while ((tmap = ft_strtok(NULL, "\n")))
	{
		tmap = ft_stroutcharset(tmap, " \t");
		if (ft_strlen(tmap) != cub->map_width)
			ft_error("problem with cub size");
		cub->tabmap[i] = ft_strdup(tmap);
		i++;
		free(tmap);
	}
	i = 0;
	while (i < cub->map_height)
		ft_str_convert(cub->tabmap[i++]);
	free(strcub);
	strcub = NULL;
	ft_check_walls(cub);
	ft_pos(cub);
	ft_set_sprites(cub);
}
