CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I $(INC_DIR)
INC_DIR = ./includes/
SRC_LIST = ft_main.c \
ft_create_tree_node.c \
ft_insert_tree_node.c \
ft_print_utils.c \
ft_queue.c \
ft_search_tree_mode.c \
ft_traversal_tree_mode.c \
ft_delete_tree_node_mode.c \
ft_remove_tree_mode.c \
ft_insertion_balancing_mode.c \
ft_rotate.c \
ft_delete_balancing_mode.c
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = avl

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

leak:
	valgrind --leak-check=full --error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leak
