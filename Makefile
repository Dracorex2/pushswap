NAME = push_swap
SRCS = algo_func.c instruction.c pushswap.c algo_push.c algo_back.c algo_func2.c function_utils.c function_utils2.c lst_function.c
OBJS = $(SRCS:.c=.o)

NAME_CHECKER = checker
SRCS_CHECKER = bonus.c instruction.c algo_func.c algo_func2.c  function_utils.c function_utils2.c  lst_function.c ./get_net_line/get_next_line.c ./get_net_line/get_next_line_utils.c
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = cc

all: $(NAME)
	@echo > /dev/null

bonus: $(NAME_CHECKER)
	@echo > /dev/null

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_CHECKER) : $(OBJS_CHECKER)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_CHECKER)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: clean fclean re all
