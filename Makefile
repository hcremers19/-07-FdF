# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 11:18:16 by hcremers          #+#    #+#              #
#    Updated: 2022/02/19 19:12:52 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c \

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJDIR	= objs/

CC		= gcc
RM		= rm -f
MKDIR	= mkdir
ZIP		= zip
MV		= mv

LIB		= srcs/libutils.a

CFLAGS	= -Wall -Wextra -Werror
MLXFLGS	= -lmlx -framework OpenGL -framework AppKit

ZIPNAME	= \[07\]FdF.zip
DISTANT	= /Volumes/Clémentine/19/

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

zip:			fclean
				$(ZIP) $(ZIPNAME) $(wildcard ./*)

xport:			zip
				$(MV) $(ZIPNAME) $(DISTANT)

.PHONY:			all clean fclean re zip
