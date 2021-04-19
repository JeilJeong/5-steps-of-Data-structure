CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./includes/
INC_FLAGS = -I $(INC_DIR)
SRCS_LIST = ft_main.c ft_crud_tree.c ft_print_tree.c ft_utils.c ft_search_tree.c ft_queue.c
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = tree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

leaks:
	valgrind --leak-check=full --error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leaks
