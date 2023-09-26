# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 07:42:45 by acharlot          #+#    #+#              #
#    Updated: 2023/09/26 09:09:39 by acharlot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variable
MAKEFLAGS	+= --silent

NAME		=	minishell
INC			=	inc/
HEADER		=	-I inc
SRC_DIR 	=	src/
OBJ_DIR 	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
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
BUILT_DIR	=	shell/
BUILT_FILES	=	builtins exec process redirect path pipe binaries heredoc

PARS_DIR	=	parsing/
PARS_FILES	=	operator parser parsing_utils quotes_handler valid_input 

SHELL_DIR	=	builtins/
SHELL_FILES	=	env echo pwd exit cd unset export export_single \
				env_utils env_utils2

EXPAND_DIR	=	expand/
EXPAND_FILES=	expand expand_utils

MAIN_DIR	=	main/
MAIN_FILES	=	main utils config_sig init utils2

SRC_BUI_FILE=	$(addprefix $(BUILT_DIR), $(BUILT_FILES))
SRC_PAR_FILE=	$(addprefix $(PARS_DIR), $(PARS_FILES))
SRC_SHE_FILE=	$(addprefix $(SHELL_DIR), $(SHELL_FILES))
SRC_EXP_FILE=	$(addprefix $(EXPAND_DIR), $(EXPAND_FILES))
SRC_MAI_FILE=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))


BSRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BUI_FILE)))
BOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BUI_FILE)))

PSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_PAR_FILE)))
POBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PAR_FILE)))

SSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SHE_FILE)))
SOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_SHE_FILE)))

ESRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_EXP_FILE)))
EOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_EXP_FILE)))

MSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAI_FILE)))
MOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAI_FILE)))

OBJF		=	.cache_exists

OBJ 		=	$(BOBJ) $(POBJ) $(SOBJ) $(EOBJ) $(MOBJ)

#Rules

all:            progress_bar message $(NAME)

message: ## Display the building of files.
					@echo "\n$(YELLOW)[Starting to build...]$(DEF_COLOR)\n\n$(MAGENTA)"

progress_bar: 
					@echo "            __      __   _   __     _   _   ______   _     _   ______   _        _                "
					@echo "      /|   |  \    /  | | | |  \   | | | | |  ____| | |   | | |  ____| | |      | |        |\     "
					@echo "     / |   |   \  /   | | | |   \  | | | | | |____  | |___| | | |___   | |      | |        | \    "
					@echo "    / /|   | |\ \/ /| | | | | |\ \ | | | | |____  | |  ___  | |  ___|  | |      | |        |\ \   "
					@echo "   / / |   | | \  / | | | | | | \ \| | | |  ____| | | |   | | | |____  | |____  | |____    | \ \  "
					@echo "  / / /|   |_|  \/  |_| |_| |_|  \___| |_| |______| |_|   |_| |______| |______| |______|   |\ \ \ "

$(NAME):		$(OBJ) $(OBJF)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@$(RM) libft/libft.a
					@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a -o $(NAME) $(READLINE)
					@$(ECHO) "$(YELLOW)[MINISHELL]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
					@$(CC) $(CFLAGS) -c $< -o $@
					@$(ECHO) "\033[1A\033[K$< created"

$(OBJF):		
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(BUILT_DIR)
					@mkdir -p $(OBJ_DIR)$(PARS_DIR)
					@mkdir -p $(OBJ_DIR)$(SHELL_DIR)
					@mkdir -p $(OBJ_DIR)$(EXPAND_DIR)
					@mkdir -p $(OBJ_DIR)$(MAIN_DIR)
					@touch $(OBJF)

help: ## Print help on Makefile.
					@grep '^[^.#]\+:\s\+.*#' Makefile | \
					sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "$(GRAY)"`\1`printf "$(DEF_COLOR)"`	\3 /" | \
					expand -t8

clean: ## Clean generated files and cache.
					@$(RM) $(OBJ_DIR)
					@$(RM) $(OBJF)
					@$(RM) libft/obj
					@$(ECHO) "$(BLUE)[MINISHELL]:\tobject files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

fclean: ## Clean all generated file, including binaries.		
					@make clean
					@$(RM) $(NAME)
					@$(RM) libft.a
					@make fclean -C $(LIBFT)
					@$(ECHO) "$(CYAN)[MINISHELL]:\texec. files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"
					
re: ## Clean and rebuild binary file.
					@make fclean all
					@$(ECHO) "\n$(GREEN)###\tCleaned and rebuilt everything for [MINISHELL]!\t###$(DEF_COLOR)\n"

.PHONY:			all clean fclean re message help