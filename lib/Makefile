# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 07:14:32 by elakhfif          #+#    #+#              #
#    Updated: 2024/06/11 07:14:42 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
SRC =        ft_calloc.c\
             ft_strcmp.c\
            ft_strchr.c\
            ft_strdup.c\
            ft_strjoin.c\
            ft_strlen.c\
            ft_strncmp.c\
            ft_strrchr.c\
            ft_strtrim.c\
            ft_substr.c\
            gnl.c\
            ohmysplit.c\
	    ft_memmove.c\
	    deg2rad.c\
	    euclidean_mod.c\
	    ft_atoi.c\

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c $(INC)                                                    
	gcc -c $(CFLAGS) $< -o $@

bonus : $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)

clean :
	@rm -rf $(OBJBONUS) $(OBJ)

fclean :
	@rm -f $(NAME) $(OBJBONUS) $(OBJ)

re : fclean all
