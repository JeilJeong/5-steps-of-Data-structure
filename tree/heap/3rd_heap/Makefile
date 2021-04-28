CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I $(INC_DIR)
INC_DIR = ./includes/
SRC_LIST = ft_main.c ft_utils.c ft_crud_heap.c ft_heap_utils.c ft_print_utils.c ft_sort_heap.c
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = heap_sort

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

leaks:
	valgrind --leak-check=full --error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leaks
