NAME 			:= push_swap

CC 				:= cc
CFLAGS 			:= -g -Wall -Wextra -Werror

LIBFT_DIR		:=	./libft
LIBFT			:=	$(LIBFT_DIR)/libft.a

HEADERS			:= -I $(LIBFT_DIR) -I./include

MAN_DIR 		:=	./source

OPS_DIR			:=	operations
STACK_DIR		:=	parse_and_init
SORT_DIR		:=	sorting
UTILS_DIR		:=	utils

OPS_FILES		:=	rotate.c			\
					swap.c				\
					reverse_rotate.c	\
					push.c
STACK_FILES		:=	parse_input.c		\
					validate_input.c	\
					init_stack.c
SORT_FILES		:= 	pa2b.c				\
					pb2a.c 				\
					sort_three.c		\
					sort_five.c
UTILS_FILES		:=	free.c				\
					utils.c

MAN_SRC			:= main.c	$(addprefix	$(MAN_DIR)/$(OPS_DIR)/,	$(OPS_FILES))	\
							$(addprefix	$(MAN_DIR)/$(STACK_DIR)/,	$(STACK_FILES))	\
							$(addprefix	$(MAN_DIR)/$(SORT_DIR)/,	$(SORT_FILES))	\
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