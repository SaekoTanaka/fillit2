NAME = fillit

SRCS = main.c open_read.c check_fit.c alpha.c movexy.c get_next_line.c keep_type.c

LIBFT_SRCS = ft_strchr.c ft_strjoin.c ft_strnew.c ft_strlen.c ft_strsub.c ft_strdup.c

OBJS = main.o open_read.o check_fit.o alpha.o movexy.o get_next_line.o keep_type.o
 
LIBFT_OBJS = ft_strchr.o ft_strjoin.o ft_strnew.o ft_strlen.o ft_strsub.o ft_strdup.o

FALGS =   -c -Wall -Werror -Wextra

$(NAME): 
	gcc $(FALGS) $(SRCS) $(LIBFT_SRCS) -I get_next_line.h fillit.h
	gcc $(OBJS) $(LIBFT_OBJS) -o $(NAME)
	rm fillit.h.gch

all: $(NAME)

clean:
	/bin/rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
