CC = cc
# NAME = so_long.a

# INCLUDES = ./mlx_linux/mlx.h
# CFLAGS = -Wall -Wextra -Werror

# RM = rm -f
# AR = ar
# ARFLAGS = crs

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = srcs/
SRCS = 	backtracking/valid_path.c \
	backtracking/collectable.c \
	backtracking/exitable.c \
	backtracking/mechable.c \
	enemy/init_enemy.c \
	enemy/move_enemy.c \
	images/check_path_1.c \
	images/check_path_2.c \
	images/charge_images_1.c \
	images/charge_images_2.c \
	images/put_image_1.c \
	images/destroy_images_1.c \
	images/destroy_images_2.c \
	main/error.c \
	main/free.c \
	main/init_1.c \
	main/init_2.c \
	main/main.c \
	main/move.c \
	main/render.c \
	main/utils.c \
	parsing/valid_map_1.c \
	parsing/valid_map_2.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING GNL ~~~~~~~ */
GNL_DIR = ./get_next_line/
GNL = get_next_line.c \
	get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx_linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
# CC = clang
CFLAGS = -Wall -Werror -Wextra -g # -MMD
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft $(LIBFT_PATH)

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f
# clang -Wall -Wextra -Werror test.c -o so_long -ldl -lmlx -Lmlx_linux -lm -lXext -lX11 -Imlx mlx_linux/libmlx.a
# /* ~~~~~~~ BONUS ~~~~~~~ */
# BONUS = so_long_bonus
# BONUS_DIR = ./bonus/
# BONUS_SRCS = 

# B_OBJS = ${addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o}}

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	# @$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(SRCS_DIR) $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

# $(BONUS): $(OBJS) $(B_OBJS)
# 	@make -C ${MLX_DIR}
# 	@cd $(LIBFT_DIR) && $(MAKE)
# 	@echo $(PURPLE) " - Compiling $@" $(RED)
# 	@$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) $(GNL_OBJS) $(BONUS_DIR)main_bonus.c $(IFLAGS) $(LFLAGS) -o $(BONUS) $(MFLAGS) 
# 	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} $(GNL_OBJS)
		@${RM} ${B_OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} $(GNL_OBJS) ${NAME}
		@${RM} ${B_OBJS} ${BONUS} 

re: 	fclean all

.PHONY: all clean fclean re
