CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

SOURCES = ft_printf.c condition1.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h 
	$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean
