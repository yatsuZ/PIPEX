# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 13:27:30 by yatsu             #+#    #+#              #
#    Updated: 2023/09/29 01:22:03 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_STRUCT		=	init_cmd.c

FOLDER_STRUC	=	struct/

STRUCT_PATH		=	${addprefix ${FOLDER_STRUC}, ${SRC_STRUCT}}


SRC_NAME_FILES	=	main.c			\
					get_path.c		\
					exec_cmd.c		\
					${STRUCT_PATH}	\

SRC_PATH		=	./src/
SRC				=	${addprefix ${SRC_PATH}, ${SRC_NAME_FILES}}

OBJ				=	${SRC:.c=.o}

CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror

MAKE_LIBFT		=	make -s -C ./library/libft
LIBFT_A			=	./library/libft/libft.a

NAME			=	pipex

RM				=	rm -rf

### Commande obligatoire

${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}

all : ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}

re : fclean all