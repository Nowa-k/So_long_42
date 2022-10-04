# Program name
NAME	= so_long
NAME_BONUS	= so_long_bonus


INC_DIR			= includes/
SRC_DIR			= srcs/
SRC_DIR_BONUS	= srcs_bonus/
OBJ_DIR			= objs/
OBJ_DIR_BONUS	= objs_bonus/

# Sources
__SRCS	=	main.c \
			get_next_line.c \
			get_next_line_utils.c \
			utils.c \
			ft_file_map.c \
			ft_parse.c \
			ft_get_info.c \
			ft_open_win.c \
			ft_loop_print.c \
			ft_key_hook.c \
			ft_itoa.c \
			ft_utils_parse.c

__SRCS_BONUS	=	main_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			utils_bonus.c \
			ft_file_map_bonus.c \
			ft_parse_bonus.c \
			ft_get_info_bonus.c \
			ft_open_win_bonus.c \
			ft_loop_print_bonus.c \
			ft_key_hook_bonus.c \
			ft_itoa_bonus.c \
			ft_move_enemy_bonus.c \
			ft_direction_asset_bonus.c \
			ft_utils_parse_bonus.c

SRCS		= 	$(addprefix $(SRC_DIR), $(__SRCS))
SRCS_BONUS	= 	$(addprefix $(SRC_DIR_BONUS), $(__SRCS_BONUS))
OBJS		=	$(addprefix $(OBJ_DIR), $(__SRCS:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(__OBJ_BONUS:.c=.o))
MLX			= 	mlx/
LINKS	= mlx/libmlx.a -framework OpenGL -framework AppKit

# Compile
CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -O3
INCLUDE	= -I $(INC_DIR)

# Color

FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

# Rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/$(NAME).h $(INC_DIR)/get_next_line.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "."

BONUS = $(SRCS_BONUS:%.c=%.o)
	

$(NAME): $(OBJS)
	@printf " [$(words $(OBJS))]\n"
	@make -s -C $(MLX) all
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS) $(OBJS) -o $(NAME)
	@printf "[ SO_LONG ] $(FG_GREE)Built '$(NAME)'.$(FG_WHIT)\n"

all: $(NAME)


bonus:	$(BONUS) includes/so_long_bonus.h includes/get_next_line_bonus.h
	@make -s -C $(MLX) all
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS) $(SRCS_BONUS) -o $(NAME_BONUS)
	@printf "[ SO_LONG_BONUS ] $(FG_GREE)Built '$(NAME_BONUS)'.$(FG_WHIT)\n"

clean:
	@rm -f $(OBJS) $(NAME)
	@printf "[ SO_LONG ] $(FG_MAGE)Build objects cleaned.$(FG_WHIT)\n"
	@rm -f $(NAME_BONUS) $(BONUS)
	@printf "[ SO_LONG_BONUS ] $(FG_MAGE)Program files cleaned.$(FG_WHIT)\n"

fclean:
	@rm -f $(NAME_BONUS) $(BONUS)
	@printf "[ SO_LONG_BONUS ] $(FG_MAGE)Program files cleaned.$(FG_WHIT)\n"
	@rm -f $(NAME) $(OBJS)
	@printf "[ SO_LONG ] $(FG_MAGE)Program files cleaned.$(FG_WHIT)\n"
	@make -s -C$(MLX) clean
	@printf "[ MLX ] $(FG_MAGE)Build objects cleaned.$(FG_WHIT)\n"

re: fclean all

.PHONY: all clean fclean re