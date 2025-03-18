NAME = philo
SRCS_DIR = ./srcs/
HEADER_DIR = ./header/

SRCS = $(SRCS_DIR)main.c $(SRCS_DIR)args_parser.c $(SRCS_DIR)death_monitor.c \
	   $(SRCS_DIR)errors_utils.c $(SRCS_DIR)init_functions.c \
	   $(SRCS_DIR)managers.c $(SRCS_DIR)philo_actions.c \
	   $(SRCS_DIR)safe_funcs.c $(SRCS_DIR)sim_funcs.c $(SRCS_DIR)utils.c

OBJS = $(SRCS:.c=.o) 

#compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I $(HEADER_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAG) -c $< -o $@

all: $(NAME)

philo: $(OBJS)
	$(CC) $(CFLAGS) $(IFLAG) $(OBJS) -gdwarf-4 -o philo

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
