# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 07:42:45 by acharlot          #+#    #+#              #
#    Updated: 2023/07/25 08:22:45 by acharlot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Variable
NAME		=	minishell
INC			=	inc/
HEADER		=	-I inc
SRC_DIR 	=	src/
OBJ_DIR 	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
LIBFT		=	libft/
RM			=	rm -rf
ECHO		=	echo

#Colors
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#Files
BUILT_DIR	=	builtins/
BUILT_FILES	=	placeholder
PARS_DIR	=	parsing/
PARS_FILES	=	placeholder 
SHELL_DIR	=	shell/
SHELL_FILES	=	placeholder
MAIN_DIR	=	main/
MAIN_FILES	=	main


SRC_BUI_FILE=	$(addprefix $(BUILT_DIR), $(BUILT_FILES))
SRC_PAR_FILE=	$(addprefix $(PARS_DIR), $(PARS_FILES))
SRC_SHE_FILE=	$(addprefix $(SHELL_DIR), $(SHELL_FILES))
SRC_MAI_FILE=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))


BSRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BUI_FILE)))
BOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BUI_FILE)))

PSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_PAR_FILE)))
POBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PAR_FILE)))

SSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SHE_FILE)))
SOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_SHE_FILE)))

MSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAI_FILE)))
MOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAI_FILE)))

OBJF		=	.cache_exists

OBJ 		=	$(BOBJ) $(POBJ) $(SOBJ) $(MOBJ)

#Rules
all:			$(NAME)

$(NAME):		$(OBJ) $(OBJF)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a -o $(NAME)
					@$(ECHO) "$(YELLOW)[MINISHELL]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):		
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(BUILT_DIR)
					@mkdir -p $(OBJ_DIR)$(PARS_DIR)
					@mkdir -p $(OBJ_DIR)$(SHELL_DIR)
					@mkdir -p $(OBJ_DIR)$(MAIN_DIR)
					@touch $(OBJF)

clean:
					@$(RM) $(OBJ_DIR)
					@$(RM) $(OBJF)
					@$(ECHO) "$(BLUE)[MINISHELL]:\tobject files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) libft.a
					@$(RM) *.dSYM
					@find . -name ".DS_Store" -delete
					@$(ECHO) "$(CYAN)[MINISHELL]:\texec. files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

re:				fclean all
					@$(ECHO) "$(GREEN)Cleaned and rebuilt everything for [MINISHELL]! $(DEF_COLOR)\n"

.PHONY:			all clean fclean re