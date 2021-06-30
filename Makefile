########
# NAME #
########

NAME = push_swap

###################
# FLAGS & LIBRARY #
###################

#compiler
CC = gcc

#compiler flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
#CFLAGS += -fsanitize=address

###################
# PRINT VARIABLES #
###################

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# One Line Output
ONELINE =\e[1A\r

############
# Includes #
############

INCLUDES += -I /includes/push_swap.h
INCLUDES += includes/libft/libft.a

########################
# Sources compilations #
########################

PATH_SRCS = srcs

SRCS += manage_errors.c 
SRCS += push_swap.c
SRCS += check_input.c
SRCS += sort_two_and_three.c
SRCS += utils_max_min.c
SRCS += sort_four_and_five.c
SRCS += utils_five_case.c
SRCS += operations_swap.c 
SRCS += operations_rotate.c
SRCS += operations_push.c
SRCS += utils_operation.c
SRCS += sort_algo.c
SRCS += recover_target_index.c
SRCS += organize_stack_a.c
SRCS += calculate_actions.c

vpath %.c $(PATH_SRCS)

########################
# Objects compilations #
########################

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

#########
# RULES #
#########

all: $(PATH_OBJS) $(NAME)

$(NAME): $(OBJS) 
		@make -C ./includes/libft
		@$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) -o $(NAME) 
		@echo "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS): $(PATH_OBJS)%.o: %.c Makefile
		@$(CC) -c $< -o $@ 
		@echo "$(ONELINE)$(CYAN)Compiling $<\n$(NC)"

$(PATH_OBJS):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATH_OBJS)
	make clean -C ./includes/libft

fclean: clean
	$(RM) $(NAME)
	$(RM) includes/libft/libft.a
	make fclean -C ./includes/libft

re: fclean all

.PHONY : all clean fclean re
