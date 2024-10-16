NAME 			:= push_swap

CC 				:= cc
CFLAGS 			:= -Wall -Wextra -Werror

LIBFT_DIR		:=	./libft
LIBFT			:=	$(LIBFT_DIR)/libft.a

HEADERS			:= -I $(LIBFT_DIR) -I./include

MAN_DIR 		:=	./source

STACK_DIR		:=	parse_and_init
UTILS_DIR		:=	utils

STACK_FILES		:=	parse_input.c
UTILS_FILES		:=	utils.c

MAN_SRC			:= main.c	$(addprefix	$(MAN_DIR)/$(STACK_DIR)/,	$(STACK_FILES))	\
							$(addprefix	$(MAN_DIR)/$(UTILS_DIR)/,	$(UTILS_FILES))

MAN_OBJ			:=	$(MAN_SRC:.c=.o)

all: LIBFT $(NAME)

$(NAME): $(MAN_OBJ) $(LIBFT)
	$(CC) $(MAN_OBJ) $(LIBFT) -o $(NAME)

%.o:	%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

LIBFT:
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning up object files..."
	@rm -f $(MAN_OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning up binaries..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re LIBFT