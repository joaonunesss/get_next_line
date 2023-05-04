# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:19:43 by jmarinho          #+#    #+#              #
#    Updated: 2023/05/04 13:12:58 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_get_next_line.c ft_get_next_line_utils.c \

NAME = nextline.a

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAG = -Wall -Werror -Wextra -D BUFFER_SIZE=xx

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	@cc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

buffer:
	@cc ${FLAGS} -c $< -o ${<:.c=.o}

re: fclean all

.PHONY: all clean fclean re

