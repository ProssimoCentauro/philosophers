NAME = philo



#compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

philo:
	$(CC) $(CFLAGS) *.c -gdwarf-4
