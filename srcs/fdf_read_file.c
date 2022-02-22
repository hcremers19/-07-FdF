/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:13:19 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/22 15:14:26 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dimensions(char *file, t_data *fdf)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		return (errors("Error: invalid path.\n", fdf));
	fdf->height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		fdf->width = 0;
		close(fd);
		return (errors("Error: empty map.\n", fdf));
	}
	fdf->width = wrdnbr(line, ' ');
	while (line)
	{
		fdf->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	fill_tab(char *file, t_data *fdf)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		while (j < fdf->width)
		{
			fdf->z[i][j] = ft_atoi(tab[j]);
			j++;
		}	
		free(line);
		tab = free_tab(tab);
		i++;
	}
	close(fd);
	return (0);
}

int	read_file(char *file, t_data *fdf)
{
	int		i;

	if (get_dimensions(file, fdf))
		return (1);
	fdf->z = (int **)malloc(sizeof(int *) * (fdf->height + 2));
	if (!fdf->z)
		return (1);
	i = 0;
	while (i <= fdf->height)
	{
		fdf->z[i] = (int *)malloc(sizeof(int) * (fdf->width + 1));
		if (!fdf->z[i])
		{
			while (i >= 0)
				free(fdf->z[i--]);
			free(fdf->z);
			fdf->z = NULL;
			return (1);
		}
		i++;
	}
	fdf->z[i] = NULL;
	return (fill_tab(file, fdf));
}
