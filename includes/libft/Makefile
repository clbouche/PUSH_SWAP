# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:17:26 by clbouche          #+#    #+#              #
#    Updated: 2021/06/30 10:13:31 by clbouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########

NAME = libft.a

###################
# FLAGS & LIBRARY #
###################

CC = gcc 

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
#CFLAGS += -fsanitize=address

#########
# PRINT #
#########

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
# INCLUDES #
############

PATH_INCLUDES = includes/
I_INCLUDES += -I $(PATH_INCLUDES)

##########
# HEADER #
##########

HEADER += libft.h

vpath %.h $(PATH_INCLUDES)

###########
# SOURCES #
###########

PATH_SRCS = srcs

# BASICS #
SRCS += ft_strlen.c
SRCS += ft_atoi.c
#SRCS += ft_itoa.c
SRCS += ft_error.c

# MANIP  STRING #
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strncmp.c
SRCS += ft_strstr.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strdup.c
SRCS += ft_substr.c
SRCS += ft_strtrim.c
SRCS += ft_split.c
SRCS += ft_strmapi.c
SRCS += ft_strchr.c
SRCS += ft_strjoin.c

# CHECK CHAR #
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# MANIP MEMORY #
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_calloc.c

# MANIP FILE #
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c

# MANIP FILE - GNL #
SRCS += get_next_line.c
SRCS += get_next_line_utils.c

# MANIP LINKED LIST #
SRCS += ft_lstnew.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstsize.c
SRCS += ft_lstlast.c
SRCS += ft_lstprint.c
#SRCS += ft_lstadd_back.c

# MANIP DOUBLE LINKED LIST #
SRCS += ft_dlstnew.c
SRCS += ft_dlstsize.c
SRCS += ft_dlstfirst.c
SRCS += ft_dlstlast.c
SRCS += ft_dlstadd_back.c
SRCS += ft_dlstadd_front.c
SRCS += print_dlist.c
SRCS += ft_dlstdelone.c
SRCS += ft_dlstdelone_back.c
SRCS += ft_dlstdelone_front.c
#SRCS += ft_dlstclear.c
	   
vpath %.c $(PATH_SRCS)

###########
# OBJECTS #
###########

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

#########
# RULES #
#########

all: $(PATH_OBJS) $(NAME) 

$(NAME): $(OBJS)
	@ar r $(NAME) $(OBJS) 
	@echo "$(GREEN)Libft done!\n"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADER) Makefile
		@echo "$(CYAN)Compiling: $<"
		@$(CC) $(I_INCLUDES) -c $< -o $@

$(PATH_OBJS): 
	@mkdir $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -R $(PATH_OBJS)
	@echo "$(RED)CLEAN"

fclean: clean 
	@$(RM) $(NAME)
	@echo "$(RED)FCLEAN"

re: fclean all

.PHONY : all clean fclean re