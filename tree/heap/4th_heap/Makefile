CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./includes/
INCFLAGS = -I $(INC_DIR)
SRC_LIST = ft_main.c \
ft_heap.c \
ft_print_utils.c
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = heap

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ $^

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