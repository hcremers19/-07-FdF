/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:13:19 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/21 17:08:40 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	return (NULL);
}

int	count_words(char *s, int c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c && flag == 1)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

int	get_dimensions(char *file, t_data *fdf)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
	{
		ft_putstr_fd("Error: invalid path\n", 1);
		free(fdf);
		return (1);
	}	
	fdf->height = 0;
	line = get_next_line(fd);
	fdf->width = count_words(line, ' ');
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
	char	**nums;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		line = get_next_line(fd);
		nums = ft_split(line, ' ');
		while (j < fdf->width)
		{
			fdf->z[i][j] = ft_atoi(nums[j]);
			j++;
		}	
		free(line);
		nums = ft_free_tab(nums);
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
	if (fill_tab(file, fdf))
		return (1);
	return (0);
}
