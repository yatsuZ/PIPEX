# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 13:27:30 by yatsu             #+#    #+#              #
#    Updated: 2023/09/30 23:37:44 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_STRUCT		=	init_cmd.c		\
					init_pipex.c

FOLDER_STRUC	=	struct/

STRUCT_PATH		=	${addprefix ${FOLDER_STRUC}, ${SRC_STRUCT}}


SRC_NAME_FILES	=	main.c			\
					get_path.c		\
					exec_cmd.c		\
					error.c			\
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
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}

re : fclean all