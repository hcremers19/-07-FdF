/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:16:51 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/22 12:27:59 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fdf.h"

void	default_values(t_data *fdf)
{
	int	max;

	max = fmax(fdf->height, fdf->width);
	fdf->size = (1000 / max);
	fdf->x_shifter = 560;
	fdf->y_shifter = 100;
	if (fdf->size <= 0 || fdf->size > 1000)
		fdf->size = 1;
}

int	deal_key(int key, t_data *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_z(fdf->z);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
	else if (key == 123)
		fdf->x_shifter -= 50;
	else if (key == 124)
		fdf->x_shifter += 50;
	else if (key == 125)
		fdf->y_shifter += 50;
	else if (key == 126)
		fdf->y_shifter -= 50;
	else if (key == 24)
		fdf->size *= 2;
	else if (key == 27)
		fdf->size /= 2;
	if (fdf->size <= 0 || fdf->size > 1000)
		fdf->size = 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*fdf;

	fdf = (t_data *)malloc(sizeof(t_data));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	if (argc == 2)
	{
		if (!read_file(argv[1], fdf))
			default_values(fdf);
		else
			return (1);
	}	
	else
		return (errors("Error: wrong number of arguments.\n", fdf));
	draw_grid(fdf);
	mlx_key_hook(fdf->win, deal_key, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
