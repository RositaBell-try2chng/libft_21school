# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbell <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 12:35:00 by rbell             #+#    #+#              #
#    Updated: 2021/10/22 13:04:41 by rbell            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c ft_calloc.c \
			  ft_isprint.c ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
			  ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_memchr.c

SRCS_BON	= ${SRCS} ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstmap.c ft_lstclear.c ft_lstnew.c ft_lstdelone.c ft_lstsize.c ft_lstiter.c

HEAD		= libft.h

OBJS		= ${SRCS:.c=.o}

OBJS_BON	= ${SRCS_BON:.c=.o}

NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:	${HEAD}
		${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${HEAD}
			ar rc ${NAME} $?
			ranlib ${NAME}

bonus:		${OBJS_BON}
			ar rc ${NAME} ${OBJS_BON}
			ranlib ${NAME}


clean:
			${RM} ${OBJS_BON}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
