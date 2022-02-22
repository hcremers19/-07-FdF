/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:47:10 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/22 12:14:08 by hcremers         ###   ########.fr       */
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
