# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 00:49:17 by yakdik            #+#    #+#              #
#    Updated: 2023/01/29 00:49:18 by yakdik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = Libft

all: $(NAME)
	gcc server.c $(NAME) -o server
	gcc client.c $(NAME) -o client

$(NAME): $(LIBFT)
	make -C $(LIBFT)
	cp Libft/libft.a .

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)
	rm -rf server client

re: fclean all
