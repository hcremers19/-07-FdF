/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:58:00 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/19 14:57:18 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "utils/libft.h"
# include "utils/get_next_line.h"
// # include "wraloc/wraloc.h"

typedef struct s_data {
	int		**z;
	void	*mlx;
	void	*win;
	void	*img_img;
	char	*img_addr;
	int		img_height;
	int		img_length;
	int		img_endian;
	int		size;
	int		width;
	int		height;
	float	x1;
	float	x0;
	float	y1;
	float	y0;
	int		z1;
	int		z0;
	int		x_shifter;
	int		y_shifter;
}	t_data;

int		linkmap(char *file, t_data *fdf);
void	drawgrid(t_data *fdf);

#endif
