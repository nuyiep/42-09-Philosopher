# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plau <plau@student.42.kl>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:10:03 by plau              #+#    #+#              #
#    Updated: 2023/01/30 17:10:53 by plau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   	philo
CC            	=    	gcc
RM            	=    	rm -f
CFLAGS       	=    	-Wall -Wextra -Werror
# CFLAGS			+=		-pthread
# CFLAGS       	+=    	-g -fsanitize=thread
SRCS_FILES    	=   	ph_main \
						ph_init \
						ph_libft \
						ph_helper \
						ph_thread 

SRCS       		=     	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        	=     	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR    	=    	srcs/
OBJS_DIR    	=    	objs/

all:             
						mkdir -p $(OBJS_DIR)
						make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				rm -rf $(OBJS_DIR)

fclean:         clean
				rm -rf $(NAME)

re:             fclean all

.PHONY:         all clean fclean re