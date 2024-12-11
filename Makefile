# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoung <djoung@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 17:13:10 by djoung            #+#    #+#              #
#    Updated: 2024/12/10 19:30:37 by djoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
SRCS			= pipex.c process.c

OBJS			= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
all:			$(NAME)

$(NAME):		$(OBJS)
				make all -C libft/
				cp libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean:
				$(RM) $(OBJS)
				make clean -C libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
