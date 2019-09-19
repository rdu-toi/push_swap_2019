NAME	= checker.a

CNAME	= ../../checker

SRCS	= checker.c list_check.c ops.c ops_2.c ops_3.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= ../libft/libft.a

GCC		= gcc -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) :
		@$(GCC) -c $(SRCS) 
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "Library [$(NAME)] updated!"

clean:
		@/bin/rm -rf $(OBJS)

libclean:
		@/bin/rm -rf $(NAME)

checkerclean:
		@/bin/rm -rf $(CNAME)

fclean: clean libclean

allclean : clean libclean checkerclean
		make fclean -C ../libft

re: allclean all ccompile
		@make fclean

ccompile:
		@make re -C ../libft
		@$(GCC) checker.c $(NAME) $(LIBFT) -o $(CNAME)

ch: all ccompile libclean clean