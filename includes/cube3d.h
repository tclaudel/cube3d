/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:06:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:49:27 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct	s_cube3d
{
	int		*R;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int		F;
	int		C;
}				t_cube3d;

typedef union		u_color
{
	int				color;
	unsigned char	argb[4];
}					t_color;


void			ft_arg_error(int ac, char *av);
int				ft_arg_analyser(int fd, t_cube3d *pf);
void			ft_error(char *error);
int				ft_convert_line(char *line, t_cube3d *pf);

#endif