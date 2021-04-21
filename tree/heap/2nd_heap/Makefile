CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I ./includes
SRCS_LIST = ft_main.c ft_crud_heap.c ft_print_utils.c ft_heap_utils.c
SRCS = $(addprefix ./srcs/, $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = heap

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
	valgrind --leak-check=full -error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leaks
