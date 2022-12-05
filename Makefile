# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 20:38:40 by moel-asr          #+#    #+#              #
#    Updated: 2022/12/05 03:36:29 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = # -Wall -Wextra -Werror

SRCS = pipex_utils/ft_putchar.c \
	pipex_utils/ft_memcpy.c \
	pipex_utils/ft_memmove.c \
	pipex_utils/ft_putstr.c \
	pipex_utils/ft_split.c \
	pipex_utils/ft_strdup.c \
	pipex_utils/ft_strjoin.c \
	pipex_utils/ft_strlen.c \
	pipex_utils/ft_strstr.c \
	pipex_utils/ft_substr.c \
	check_errors.c \
	print_errors.c \
	main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run :
	@./$(NAME)

.PHONY : clean fclean bonus