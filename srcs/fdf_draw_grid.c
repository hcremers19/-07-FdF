/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:17:49 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/21 19:29:13 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspect(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.6) - z;
}

void	drawline(t_data *fdf)
{
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
	fdf->dx = tempx1 - tempx0;
	fdf->dy = tempy1 - tempy0;
	fdf->max = fmax(fabs(fdf->dx), fabs(fdf->dy));
	fdf->dx /= fdf->max;
	fdf->dy /= fdf->max;
	while ((int)(tempx0 - tempx1) || (int)(tempy0 - tempy1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win,
			tempx0 + fdf->x_shifter, tempy0 + fdf->y_shifter, 0xffffff);
		tempx0 += fdf->dx;
		tempy0 += fdf->dy;
	}
}

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
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = 0;
	fdf->y1 = 0;
	draw_x(fdf);
	draw_y(fdf);
}
