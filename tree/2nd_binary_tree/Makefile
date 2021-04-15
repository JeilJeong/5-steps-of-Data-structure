CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_tree.c ft_main.c
DIR_SRCS = $(addprefix ./srcs/, $(SRCS))
OBJS = $(DIR_SRCS:.c=.o)
INC_DIR = ./includes/
INC_FLAGS = -I $(INC_DIR)
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

.PHONY: all clean fclean re
