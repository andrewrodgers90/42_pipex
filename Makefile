# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodgers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:26:32 by arodgers          #+#    #+#              #
#    Updated: 2023/12/07 13:20:33 by arodgers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Werror -Wextra

HDR    = pipex.h
NAME   = pipex
SRCS   = pipex.c pipex_utils.c pipex_utils_extra.c libft_utils.c libft_utils_extra.c

OBJS   = $(SRCS:.c=.o)

RM     = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HDR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
