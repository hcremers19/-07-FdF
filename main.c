/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:16:51 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/19 19:09:46 by hcremers         ###   ########.fr       */
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

void	*ft_free_itab(int **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

int	deal_key(int key, t_data *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		ft_free_itab(fdf->z);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
	else if(key == 123)
		fdf->x_shifter -= 50;
	else if(key == 124)
		fdf->x_shifter += 50;
	else if(key == 125)
		fdf->y_shifter += 50;
	else if(key == 126)
		fdf->y_shifter -= 50;
	else if(key == 24)
		fdf->size *= 2;
	else if(key == 27)
		fdf->size /= 2;
	else
		printf("Congrats! You pressed key nbr %d, this key is absolutely useless.\n", key);
	// mlx_destroy_image(fdf->mlx, fdf->img_img);
	if (fdf->size <= 0 || fdf->size > 1000)
		fdf->size = 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	drawgrid(fdf);
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
		if (!linkmap(argv[1], fdf))
			default_values(fdf);
		else
			return (1);
	}	
	else
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 1);
		free(fdf);
		return (1);
	}
	ft_putstr_fd("height = ", 1); ft_putnbr_fd(fdf->height, 1); ft_putchar_fd(10, 1);
	ft_putstr_fd("width = ", 1); ft_putnbr_fd(fdf->width, 1); ft_putchar_fd(10, 1);
	drawgrid(fdf);
	if (!mlx_key_hook(fdf->win, deal_key, fdf))
		return (0);
	mlx_loop(fdf->mlx);
	return (0);
}
