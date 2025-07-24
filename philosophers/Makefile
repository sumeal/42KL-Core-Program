NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = main.c \
		activities.c \
		free.c \
		init.c \
		libft.c \
		parsing.c \
		routine.c \
		utils.c

OFILES = $(FILES:.c=.o)

$(NAME) : $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

me:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) clean

.PHONY: all clean fclean re me
