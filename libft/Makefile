# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleonard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:14:58 by eleonard          #+#    #+#              #
#    Updated: 2019/09/25 19:22:34 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =           ft_atoi.c 			ft_bzero.c 			ft_strchr.c \
         	    ft_check_overlap.c	ft_isalnum.c		ft_isalpha.c \
         		ft_isascii.c 		ft_isdigit.c		ft_isprint.c \
         		ft_memalloc.c		ft_memccpy.c		ft_memchr.c \
         		ft_memcmp.c			ft_memcpy.c			ft_memdel.c \
         		ft_memmove.c		ft_memset.c			ft_putchar.c \
         		ft_putendl.c		ft_putnbr.c			ft_putstr.c \
         		ft_strcat.c			ft_strclr.c			ft_strcmp.c \
         		ft_strcpy.c			ft_strdel.c			ft_strdup.c \
         		ft_strequ.c			ft_striter.c		ft_striteri.c \
         		ft_strjoin.c		ft_strlcat.c		ft_strlen.c \
         		ft_strmap.c			ft_strmapi.c		ft_strncat.c \
         		ft_strncmp.c		ft_strncpy.c		ft_strnequ.c \
         		ft_strnew.c			ft_strsplit.c		ft_strstr.c \
         		ft_strsub.c			ft_strtrim.c		ft_tolower.c \
         		ft_toupper.c		ft_strrchr.c		ft_strnstr.c \
				ft_itoa.c			ft_lstnew.c			ft_lstadd.c \
				ft_lstdelone.c		ft_lstdel.c			ft_lstiter.c \
				ft_lstmap.c			ft_lstaddtoend.c	ft_putchar_fd.c \
				ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c \
				ft_sqrt.c			ft_freep.c

NAME	= libft.a

OBJ		= $(SRC:.c=.o)
	INC		= -I includes
	FLAGS	= -Wall -Wextra -Werror

SRCDIR	= srcs/
OBJDIR	= objs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(OBJS): $(SRCS)
	@/bin/mkdir -p $(OBJDIR)
	@gcc -c $(FLAGS) $(SRCS) $(INC)
	@/bin/mv $(OBJ) $(OBJDIR)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@

clean:
		@/bin/rm -rf $(OBJDIR)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
