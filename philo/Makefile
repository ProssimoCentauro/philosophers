NAME = philo

SRCS = main.c args_parser.c death_monitor.c \
       errors_utils.c init_functions.c \
       managers.c philo_actions.c \
       safe_funcs.c sim_funcs.c utils.c

OBJS = $(SRCS:.c=.o) 

#compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

philo: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -gdwarf-4 -o philo

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
