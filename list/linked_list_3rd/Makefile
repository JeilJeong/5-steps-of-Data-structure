CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./includes
SRCS = ft_main.c ft_error.c ft_list.c
SRCS_DIR = $(addprefix ./srcs/, $(SRCS))
OBJS = $(SRCS_DIR:.c=.o)
NAME = list

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
