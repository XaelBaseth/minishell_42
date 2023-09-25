#Variables
MAKEFLAGS += --silent

NAME		=	libft.a
INCLUDE		=	inc/
SRC_DIR 	=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs
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

#Sources

FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset ft_memcpy

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper ft_atoll

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strcmp \
				ft_strncpy ft_strstr

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

GNL_DIR		=	gnl/
GNL			=	get_next_line

FTPRINTF_DIR	= ft_printf/
FTPRINTF	=	ft_printf ft_printf_utils ft_printf_hex ft_printf_ptr ft_printf_unsigned

FTGC_DIR	=	ft_gc_alloc/
FTGC		=	ft_gc_alloc ft_gc_alloc_lst

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))
SRC_FILES+=$(addprefix $(FTGC_DIR), $(FTGC))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Rules

OBJF		=	.cache_exists
all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@$(ECHO) "\n$(YELLOW)[LIBFT]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
			@$(ECHO) "\033[1A\033[K$< created"

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(FTIS_DIR)
			@mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
			@mkdir -p $(OBJ_DIR)$(FTTO_DIR)
			@mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJ_DIR)$(FTLST_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
			@mkdir -p $(OBJ_DIR)$(FTGC_DIR)
			@touch $(OBJF)

help: ## Print help on Makefile.
					@grep '^[^.#]\+:\s\+.*#' Makefile | \
					sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "$(GRAY)"`\1`printf "$(DEF_COLOR)"`	\3 /" | \
					expand -t8

clean: ## Clean generated files and cache.
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@$(RM) .cache_exists
			@echo "$(BLUE)[LIBFT]:\tobject files$(DEF_COLOR)$(GREEN)\t => Cleaned!$(DEF_COLOR)\n"

fclean: ## Clean all generated file, including binaries.
			make clean
			@$(RM) $(NAME)
			@echo "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)\t => Cleaned!$(DEF_COLOR)\n"

re: ## Clean and rebuild binary file.
			@make fclean all
			@$(ECHO) "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)\n"

.PHONY:		all clean fclean re