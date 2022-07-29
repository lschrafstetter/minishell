# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 16:58:21 by lschrafs          #+#    #+#              #
#    Updated: 2022/07/29 11:13:19 by lschrafs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

COMPILER 	= cc
CFLAGS 		= -Wall -Wextra -Werror

MYLIBS 		= libft/libft.a
LIBS 		= -lreadline

SRCS_PATH 	= ./src/
SRCS_NAMES	= main ms_signaling ms_list ms_data_init

SRCS		= $(addprefix $(SRCS_PATH), $(SRC_NAMES))

OBJS_PATH	= ./obj/
OBJS_NAMES	= $(SRCS_NAMES:%=%.o)
OBJS		= $(addprefix $(OBJS_PATH), $(OBJS_NAMES))

all: $(NAME)

$(NAME): $(OBJS) $(MYLIBS)
	$(COMPILER) $(CFLAGS) $(OBJS) $(MYLIBS) $(LIBS) -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(OBJS_PATH)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(MYLIBS): FORCE
	make -C $(dir $@)

FORCE: ;

clean:
	rm -rf $(OBJS_PATH)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all