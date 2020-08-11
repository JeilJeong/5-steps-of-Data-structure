CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/
OPTION = -I $(HEADER)
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
SRC = main.c selection_sort.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re
