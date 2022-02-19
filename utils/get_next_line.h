/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:46:17 by hcremers          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:55 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
// # include "../wraloc/wraloc.h"

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