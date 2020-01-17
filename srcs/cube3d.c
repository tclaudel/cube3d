/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:20:20 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 16:20:31 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_grep_flags(t_cub *cub, int ac, char **av)
{
	if (ac > 3)
		ft_error("please, give me only one flag");
	else if (!ft_strncmp(av[2], "-m", 3))
		cub->flag = 'm';
	else if (!ft_strncmp(av[2], "-save", 6) ||
		!ft_strncmp(av[2], "--save", 7) || !ft_strncmp(av[2], "-s", 3))
		cub->flag = 's';
	else if (!ft_strncmp(av[2], "-edit", 6))
	{
		cub->flag = 'e';
		cub->maxlife = EDITO_LIFE;
	}
	else if (!ft_strncmp(av[2], "-difficulty=1", 14))
		cub->maxlife = 6;
	else if (!ft_strncmp(av[2], "-difficulty=2", 14))
		cub->maxlife = 3;
	else if (!ft_strncmp(av[2], "-difficulty=3", 14))
		cub->maxlife = 2;
	else
		ft_error("wrong flag inserted");
}

void			ft_free_still(char **av)
{
	free(av[0]);
	free(av[1]);
	free(av);
}

void			ft_start(int ac, char **av, int i, char flag)
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
	cub->victory = i > 1 ? 1 : 0;
	cub->flag = flag;
	cub->maxlife = 0;
	if (ac >= 3)
		ft_grep_flags(cub, ac, av);
	if (cub->maxlife == 0)
		cub->maxlife = 3;
	ft_arg_error(av[1]);
	if (i >= 1)
		ft_free_still(av);
	ft_arg_analyser(fd, cub);
	ft_cub(cub);
}

int				main(int ac, char **av)
{
	ft_start(ac, av, 0, 0);
}
