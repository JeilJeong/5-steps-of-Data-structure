CC = gcc
CFLAGS =
SRC = a_list.c
OBJ = $(SRC:.c=.o)
TARGET = a_list
HEADER = a_list.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -I $(HEADER) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

leak:
	valgrind --leak-check=yes ./$(TARGET)

.PHONY: all clean fclean re leak
