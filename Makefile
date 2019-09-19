all:
	@make all -C srcs/push_swap
	@make all -C srcs/checker

allcompile:
	@make pcompile -C srcs/push_swap
	@make ccompile -C srcs/checker

re:
	@make re -C srcs/push_swap
	@make re -C srcs/checker

clean:
	@make clean -C srcs/push_swap
	@make clean -C srcs/checker

fclean:
	@make fclean -C srcs/push_swap
	@make fclean -C srcs/checker

pcompile:
	@make pcompile -C srcs/push_swap

ccompile:
	@make ccompile -C srcs/checker

libclean:
	@make libclean -C srcs/push_swap
	@make libclean -C srcs/checker

psclean:
	@make psclean -C srcs/push_swap

checkerclean:
	@make checkerclean -C srcs/checker

allclean:
	@make allclean -C srcs/push_swap
	@make allclean -C srcs/checker

ps:
	@make ps -C srcs/push_swap

ch:
	@make ch -C srcs/checker