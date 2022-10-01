NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=thread

SRCS = philo.c parse_utils.c libft_utils.c routines.c threads.c

OBJS = ${SRCS:.c=.o}

RM = rm -r

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $^

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

tag:
	ctags $(SRCS)

run:
	./$(NAME) 4 4000 2000 2000 2
.PHONY: clean re fclean all
