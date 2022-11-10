# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 11:18:16 by hcremers          #+#    #+#              #
#    Updated: 2022/11/10 11:51:16 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c \

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJDIR	= objs/

CC		= gcc
RM		= rm -f
MKDIR	= mkdir

LIB		= srcs/libutils.a

CFLAGS	= -Wall -Wextra -Werror
MLXFLGS	= -lmlx -framework OpenGL -framework AppKit 									# MacOS
# MLXFLGS		= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz	# Linux

###############################################################################

$(OBJDIR)%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJDIR), $(<:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C srcs/
				$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MLXFLGS) -o $(NAME)

$(OBJ):			| $(OBJDIR)

$(OBJDIR):		
				$(MKDIR) $(OBJDIR)

clean:
				make clean -C srcs/
				$(RM) $(wildcard *.o)
				$(RM) -r $(OBJDIR)

fclean:			clean
				make fclean -C srcs/
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
