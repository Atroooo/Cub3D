 .PHONY:     			all $(NAME) mkbuild lib clean fclean re 

NAME					= cub3D

BUILD_DIR				= build/
	
HEADER_DIR				= includes/


DIR						= srcs/
SRC			 			= main.c \
						  free_functions/free.c \
						  parsing/parsing.c \
						  parsing/parsing_utils.c \
						  parsing/get_resol.c \
						  parsing/get_texture.c \
						  parsing/get_color.c \
						  parsing/get_map.c \
						  delete.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror -g3  

RM 						= rm -rf


$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR) Makefile 
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -c $< -o $@
					
all: 					 mkbuild lib $(HEADER_DIR) $(NAME)

mkbuild:
						@mkdir -p build
					
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) -I{HEADER_DIR} $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)

lib:
						@make -C $(LIB_DIR)
		
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all
						$(MAKE) all
