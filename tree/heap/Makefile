CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_LIST = ft_main.c ft_heap.c
SRCS = $(addprefix ./srcs/, $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
INC_DIR = ./includes/
INC_FLAGS = -I $(INC_DIR)
TARGET = heap

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
