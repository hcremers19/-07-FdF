/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:47:10 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/22 15:14:24 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	errors(char *error, t_data *fdf)
{
	ft_putstr_fd(error, 1);
	free(fdf);
	return (1);
}

void	*free_tab(char **tab)
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

void	*free_z(int **z)
{
	int	i;

	if (!z)
		return (NULL);
	i = 0;
	while (z[i])
	{
		free(z[i]);
		z[i] = NULL;
		i++;
	}
	free(z);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = ft_strlen(src);
	if (!dstsize)
		return (s);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
