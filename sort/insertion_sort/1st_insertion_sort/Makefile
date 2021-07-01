CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ./includes/
INCFLAG = -I $(INC)
SRC_LIST = ft_main.c \
ft_insertion_sort.c
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = sort

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLFAG) -o $@ $^

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