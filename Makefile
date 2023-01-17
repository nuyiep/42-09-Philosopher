# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plau <plau@student.42.kl>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:10:03 by plau              #+#    #+#              #
#    Updated: 2023/01/17 19:30:37 by plau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   	philo
LIBFT        	=    	libft.a
CC            	=    	gcc
RM            	=    	rm -f
CFLAGS       	=    	-Wall -Wextra -Werror
# CFLAGS       	+=    	-fsanitize=address -g3
SRCS_FILES    	=   	ph_main
SRCS       		=     	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        	=     	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR    	=    	srcs/
LIBFT_DIR    	=    	libft/
OBJS_DIR    	=    	objs/

all:             
						mkdir -p $(OBJS_DIR)
						make libft
						make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:         clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:             fclean all

.PHONY:         all libft clean fclean re