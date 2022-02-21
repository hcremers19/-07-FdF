/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:58:00 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/21 19:23:11 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "wraloc/wraloc.h"

/**** Fdf ****/

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
	float	dx;
	float	dy;
	int		max;
	int		x_shifter;
	int		y_shifter;
}	t_data;

void	drawgrid(t_data *fdf);
int		read_file(char *file, t_data *fdf);

/**** libft ****/

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**** get_next_line ****/

char	*ft_calloc(size_t count, size_t size);
void	ft_free(char **ptr);
char	*ft_keepend(char *ptr);
char	*ft_keepstart(char *ptr);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_srch_nl(const char *str);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
