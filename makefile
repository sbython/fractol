# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msbai <msbai@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 18:30:22 by msbai             #+#    #+#              #
#    Updated: 2024/05/06 21:36:24 by msbai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
BONUS = fractal_bonus
NAME = fractal

SUR = mandatory/main.c mandatory/julia.c mandatory/mandelbrot.c mandatory/tools.c\
		mandatory/tools1.c mandatory/ft_putnbr.c mandatory/event.c mandatory/ft_atdo.c
BON = bonus/event.c   bonus/main.c  bonus/bonus.c  bonus/tools1.c  bonus/tools.c
OBJ = $(SUR:.c=.o)
OBJB = $(BON:.c=.o)
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux  -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: $(OBJB)
	$(CC) $(OBJB) -Lmlx_linux -lmlx_Linux  -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS)
clean:
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME) $(BONUS)
re: fclean all 

.PHONY: all re fclean clean 
