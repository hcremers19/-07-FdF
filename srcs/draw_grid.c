/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:17:49 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/19 18:15:58 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	mlx_put_pixel_to_image(t_data *fdf, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = fdf->img_addr + (y * fdf->img_length + x * (fdf->img_height / 8));
// 	*(unsigned int *)dst = color;
// }

void	perspect(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.6) - z;
}

void	drawline(t_data *fdf)
{
	float	dx;
	float	dy;
	int		max;
	float	tempx0;
	float	tempy0;
	float	tempx1;
	float	tempy1;

	tempx0 = fdf->x0;
	tempy0 = fdf->y0;
	tempx1 = fdf->x1;
	tempy1 = fdf->y1;
	fdf->z0 = fdf->z[(int)tempy0 / fdf->size][(int)tempx0 / fdf->size];
	fdf->z1 = fdf->z[(int)tempy1 / fdf->size][(int)tempx1 / fdf->size];
	perspect(&tempx0, &tempy0, fdf->z0);
	perspect(&tempx1, &tempy1, fdf->z1);
	dx = tempx1 - tempx0;
	dy = tempy1 - tempy0;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(tempx0 - tempx1) || (int)(tempy0 - tempy1))
	{
		// mlx_put_pixel_to_image(fdf, tempx0 + fdf->x_shifter, tempy0 + fdf->y_shifter, 0xffffff);
		mlx_pixel_put(fdf->mlx, fdf->win, tempx0 + fdf->x_shifter, tempy0 + fdf->y_shifter, 0xffffff);
		tempx0 += dx;
		tempy0 += dy;
	}
}//	Raccourcir en incluant dx, dy ou max dans t_data fdf ? 

void	draw_x(t_data *fdf)
{
	int	h;
	int	w;

	h = 0;
	while (h < fdf->height)
	{
		w = 0;
		while (w < fdf->width - 1)
		{
			fdf->x1 += fdf->size;
			drawline(fdf);
			fdf->x0 += fdf->size;
			w++;
		}
		fdf->x0 = 0;
		fdf->x1 = 0;
		fdf->y0 += fdf->size;
		fdf->y1 += fdf->size;
		h++;
	}
	fdf->y0 = 0;
	fdf->y1 = 0;
}

void	draw_y(t_data *fdf)
{
	int	h;
	int	w;

	w = 0;
	while (w < fdf->width)
	{
		h = 0;
		while (h < fdf->height - 1)
		{
			fdf->y1 += fdf->size;
			drawline(fdf);
			fdf->y0 += fdf->size;
			h++;
		}
		fdf->y0 = 0;
		fdf->y1 = 0;
		fdf->x0 += fdf->size;
		fdf->x1 += fdf->size;
		w++;
	}
	fdf->x0 = 0;
	fdf->x1 = 0;
}

void	drawgrid(t_data *fdf)
{
	// fdf->img_img = mlx_new_image(fdf->mlx, 1920, 1080);
	// fdf->img_addr = mlx_get_data_addr(fdf->img_img, &fdf->img_height, &fdf->img_length, &fdf->img_endian);
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = 0;
	fdf->y1 = 0;
	draw_x(fdf);
	draw_y(fdf);
	ft_putstr_fd("size = ", 1); ft_putnbr_fd(fdf->size, 1); ft_putchar_fd(10, 1);
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_img, 0, 0);
}
