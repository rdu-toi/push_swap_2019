all:
	@make all -C push_swap_src
	@make all -C checker_src

allcompile:
	@make pcompile -C push_swap_src
	@make ccompile -C checker_src

re:
	@make re -C push_swap_src
	@make re -C checker_src

clean:
	@make clean -C push_swap_src
	@make clean -C checker_src

fclean:
	@make fclean -C push_swap_src
	@make fclean -C checker_src

pcompile:
	@make pcompile -C push_swap_src

ccompile:
	@make ccompile -C checker_src

libclean:
	@make libclean -C push_swap_src
	@make libclean -C checker_src

psclean:
	@make psclean -C push_swap_src

checkerclean:
	@make checkerclean -C checker_src

allclean:
	@make allclean -C push_swap_src
	@make allclean -C checker_src

ps:
	@make ps -C push_swap_src

ch:
	@make ch -C checker_src