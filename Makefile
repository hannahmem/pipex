NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = rm -f

SRC_FILES = main.c outils.c
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_LIB)

%.o: %.c includes/pipex_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re