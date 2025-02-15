NAME = pipex

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/execute.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re