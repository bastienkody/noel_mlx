###		DIRECTORY		###
HEADER		=	noel.h
BUILD_DIR	=	./build
SRC_DIR 	=	src/
PRINT_DIR	=	printer/
DISP_DIR	=	display/
vpath %.h ./inc
vpath %.c ./src ./src/${PRINT_DIR} ./src/${DISP_DIR}

###		SOURCE FILES		###
PRINT_NAME	=	
DISP_NAME	=	init.c\
				image_utils.c\
				drawers.c\
				hooks.c\

SRCS 	=	main.c error.c ${DISP_NAME} 
OBJS		=	${SRCS:%.c=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	noel_mlx_fireplace
LIBFT		=	./libs/libft/libft.a
MLX			=	./libs/mlx/libmlx.a
XWIN		=	-lXext -lX11
SHELL		=	/bin/bash
CC			=	cc

###		SCREEN RES		###
DIM			:=	$(shell xdpyinfo | grep dim | grep -o "[0-9]*x[0-9]* pixels")
WIDTH		:=	$(shell echo ${DIM} | cut -d'x' -f1 | grep -o "[0-9]*")
HEIGHT		:=	$(shell echo ${DIM} | cut -d'x' -f2 | grep -o "[0-9]*")
RES_ALERT	:=	"\033[31mScreen res is lower than 1920x1080. You might not enjoy the game, please change hardware.\033[m"
RES_OK		:=	"\033[32mScreen display set to 1920x1080. Launch game with: \033[4\;36\;1m\.\/cub3D \<map\.cub\>\033[m"

###		OPTIONS		##
CFLAGS		=	-Wall -Wextra -Werror -g3
LDFLAGS		=	${LIBFT} ${MLX} ${XWIN}
REDIRVOID	=	>/dev/null 2>&1

###		RULES		###
$(BUILD_DIR)/%.o: %.c ${HEADER}
			@mkdir -p $(dir $@)
			@echo -e "\033[32m\c"
			${CC} ${CFLAGS} -c $< -o $@
			@echo -e "\033[0m\c"

all:		${NAME} screen_res_alert

${NAME}:	${LIBFT} ${MLX} ${OBJS} ${HEADER}
			@echo -e "\033[32m\c"
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}
			@echo -e "Link complete for exec --> \033[4;36;1m${NAME}\033[0m"

${LIBFT}:
			@echo -ne "\033[33mlibft: compilation ...\033[0m"
			@make --no-print-directory -C ./libs/libft/
			@echo -e "\r\033[33mlibft: compiled!           \033[0m"

screen_res_alert:
		@echo -e $(shell [[ ${WIDTH} -ge 1920 && ${HEIGHT} -ge 1080 ]] && echo -e ${RES_OK} || echo -e ${RES_ALERT} )

${MLX}:
			@echo -ne "\033[33mmlx: compilation ...\033[0m"
			@make --no-print-directory -C ./libs/mlx >/dev/null 2>&1
			@echo -e "\r\033[33mmlx: compiled!            \033[0m"

clean:
			@make --no-print-directory clean -C ./libs/libft/ >/dev/null 2>&1
			@make --no-print-directory clean -C ./libs/mlx/ >/dev/null 2>&1
			@rm -rf ${BUILD_DIR}
			@echo -e "\033[32m${NAME} obj cleaned"

fclean:		clean
			@make --no-print-directory fclean -C ./libs/libft/
			@rm -rf ${NAME}
			@echo -e "\033[32m${NAME} fcleaned\033[m"

re:			fclean all

.PHONY:		all clean re screen_res_alert
