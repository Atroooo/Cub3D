.PHONY: all clean fclean re

NAME 			= libft.a

BUILD_DIR		= build/

SRCS_PRINTF		= ft_printf.c ft_printf_nb.c ft_printf_str.c
SRCS_DIR_PR		= ft_printf/
OBJS_PR 		= ${SRCS_PRINTF:%.c=$(BUILD_DIR)%.o}

SRCS_IS				= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRCS_DIR_IS		= is_functions/
OBJS_IS 		= ${SRCS_IS:%.c=$(BUILD_DIR)%.o}

SRCS_LST		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS_DIR_LS		= lst_functions/
OBJS_LS 		= ${SRCS_LST:%.c=$(BUILD_DIR)%.o}

SRCS_MALLOC		= ft_bzero.c ft_calloc.c
SRCS_DIR_MA		= malloc_functions/
OBJS_MA 		= ${SRCS_MALLOC:%.c=$(BUILD_DIR)%.o}

SRCS_MEM		= ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
SRCS_DIR_ME		= mem_functions/
OBJS_MEM 		= ${SRCS_MEM:%.c=$(BUILD_DIR)%.o}

SRCS_PUT		= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_DIR_PU		= put_functions/
OBJS_PU 		= ${SRCS_PUT:%.c=$(BUILD_DIR)%.o}

SRCS_STR		= ft_strlen.c  ft_strlcpy.c	ft_strlcat.c  ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_strnjoin.c
SRCS_DIR_ST		= str_functions/
OBJS_ST 		= ${SRCS_STR:%.c=$(BUILD_DIR)%.o}

SRCS_TO			= ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c get_next_line.c get_next_line_utils.c
SRCS_DIR_TO		= to_functions/
OBJS_TO 		= ${SRCS_TO:%.c=$(BUILD_DIR)%.o}

OBJS			= $(OBJS_PR) $(OBJS_IS) $(OBJS_LS) $(OBJS_MA) $(OBJS_MEM) $(OBJS_PU) $(OBJS_ST) $(OBJS_TO)		 

CC 				= gcc
FLAGS 			= -Wall -Wextra -Werror

HEADER 			= header/libft.h

LIB 			= ar rc

RM 				= rm -f

all:    		${NAME} Makefile

$(BUILD_DIR)%.o:	$(SRCS_DIR_PR)%.c ${HEADER}
					@mkdir -p build
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_IS)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_LS)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_MA)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_ME)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_PU)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_ST)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(BUILD_DIR)%.o:	$(SRCS_DIR_TO)%.c ${HEADER} 
					${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME):    	$(OBJS) Makefile
				${LIB} ${NAME} $(OBJS)

clean:
				${RM} build/*.o

fclean:     	clean
				${RM} ${NAME}

re:        		fclean all