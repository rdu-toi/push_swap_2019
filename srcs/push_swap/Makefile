NAME	=	push_swap.a

CNAME	=	../../push_swap

SRCS	=	best_move.c push_swap.c ops.c ops_2.c ops_3.c norm_made_me_do_this.c sort_five_below.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	../libft/libft.a

GCC		=	gcc -Wall -Werror -Wextra -g

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

psclean:
		@/bin/rm -rf $(CNAME)

fclean: clean libclean

allclean : clean libclean psclean
		make fclean -C ../libft

re: allclean all pcompile
		@make fclean

pcompile:
		@make re -C ../libft
		@$(GCC) push_swap.c $(NAME) $(LIBFT) -o $(CNAME)

ps: all pcompile libclean clean