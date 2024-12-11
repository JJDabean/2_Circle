# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 16:57:36 by djoung            #+#    #+#              #
#    Updated: 2024/10/17 00:05:13 by djoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c \
					ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_strdup.c  ft_strlen.c \
					ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_atoi.c ft_calloc.c ft_toupper.c \
					ft_strnstr.c ft_strrchr.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c get_next_line.c

BONUS_SRCS		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $^
				@touch $@

clean:
				$(RM) $(OBJS) $(BONUS_OBJS) bonus

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
