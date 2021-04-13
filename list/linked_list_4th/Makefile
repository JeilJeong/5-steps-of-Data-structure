CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_list.c ft_main.c ft_sort.c
DIR_SRCS = $(addprefix ./srcs/, $(SRCS))
OBJS = $(DIR_SRCS:.c=.o)
INC_DIR = ./includes/
INC_FLAG = -I $(INC_DIR)
TARGET = list

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAG) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re
