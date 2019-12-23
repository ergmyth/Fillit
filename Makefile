# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleonard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 15:05:38 by eleonard          #+#    #+#              #
#    Updated: 2019/09/25 19:31:18 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALL_EX = main.c read_here.c check_buffer.c buffer_to_map.c \
							 check_shape.c ft_append.c fillit.c check_size.c \
							 int_array.c new_tetrm.c ft_lstclear.c case_of_error.c

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(ALL_EX))

ALL_OBJ = $(ALL_EX:%.c=%.o)

OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))

NAME = fillit

INCLUDES = ./includes/fillit.h ./libft/includes/libft.h

COMP_LIB = make -C libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP_LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L./libft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
	/bin/mkdir -p $(OBJDIR)
	gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

clean:
	/bin/rm -rf $(OBJDIR)
	$(COMP_LIB) clean

fclean: clean
	/bin/rm -rf $(NAME)
	$(COMP_LIB) fclean

re: fclean all

.PHONY: clean fclean all re
