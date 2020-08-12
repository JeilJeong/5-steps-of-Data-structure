CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/
OPTION = -I $(HEADER)
SRC_DIR = ./srcs/
SRCS = main.c selection_sort.c b_search.c
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))
TARGET = test

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re
