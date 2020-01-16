/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 16:39:27 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_grep_flags(t_cub *cub, int ac, char **av)
{
	if (ac > 3)
		ft_error("please, give me only one flag");
	if (!ft_strncmp(av[2], "-m", 3))
		cub->flag = 'm';
	else if (!ft_strncmp(av[2], "-save", 6) ||
		!ft_strncmp(av[2], "--save", 7) || !ft_strncmp(av[2], "-s", 3))
		cub->flag = 's';
	else
		ft_error("wrong flag inserted");
}

int				ft_start(int ac, char **av, int i)
{
	int				fd;
	t_cub			*cub;
	char			*map;

	if (ac == 1)
		ft_error("please insert map");
	if (!(map = ft_strrchr(av[1], '.')))
		ft_error("Wrong map extension, should be .cub");
	if (ft_strncmp(".cub", map, 5))
		ft_error("Wrong map extension, should be .cub");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("could not find the map");
	cub = init_cub();
	if (ac >= 3)
	{
		ft_grep_flags(cub, ac, av);
	}
	ft_arg_error(av[1]);
	if (i == 1)
	{	
		free(av[0]);
		free(av[1]);
		free(av);
	}
	ft_arg_analyser(fd, cub);
	ft_cub(cub);
	return (1);
}

int				main(int ac, char **av)
{
	ft_start(ac, av, 0);
}
