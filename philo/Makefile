NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lpthread
SRCS =	./philo_main.c\
		./philo_utils.c\
		./philo_action.c\
		./actions.c\
		./philo_create_pthreads.c\
		./init/philo_init.c\
		./init/philo_create.c\
		./init/philo_struct_fill.c\
		./init/philo_struct_compound.c

HEAD = philo.h
OFILE = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	$(CC) -o $(NAME) $(OFILE)

clean: 
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re %.o