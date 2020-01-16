/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_bitmap.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 13:30:00 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:20:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_bitmap_image(t_cub *c, int fd, t_bpm2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = c->res[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->res[0])
		{
			ble = c->dp.img_data[y * c->res[0] + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void			ft_save_bitmap(const char *filename, t_cub *c)
{
	int			fd;
	t_bpm		bfh;
	t_bpm2		bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = c->res[0] * c->res[1] * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = c->res[0];
	bih.height = c->res[1];
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = c->res[0] * c->res[1] * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	ft_bitmap_image(c, fd, bih);
	close(fd);
}
