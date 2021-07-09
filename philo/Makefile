NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	./main/philo_main.c\
		./main/philo_clear.c\
		./main/philo_utils.c\
		./main/philo_create_pthreads.c\
		./threads/actions.c\
		./threads/message.c\
		./threads/philo_action.c\
		./init/philo_init.c\
		./init/philos_create.c\
		./init/philos_struct_fill.c\
		./init/philos_struct_compound.c

HEAD = philo.h
OFILE = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	$(CC) -o $(NAME) $(OFILE) -lpthread

clean: 
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re %.o