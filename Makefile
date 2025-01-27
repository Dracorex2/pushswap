NAME = pushswap
SRCS =  algo_func.c  instruction.c  pushswap.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iutils
CC = cc

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all