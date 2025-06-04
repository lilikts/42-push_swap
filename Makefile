NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := ./includes
SRC_DIRS := ./srcs
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

LIBFT_DIR = $(INC_DIRS)/libft
LIBFT = libft.a
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_REPO = https://github.com/lilikts/42-Libft.git

SRCS =	main.c \
		input.c \
		utils.c \
		validate_arguments.c \
		operations.c \
		stack_handling.c \
		algorithm.c \
		error_management.c \
		execute_cheapest.c \
		create_stack.c \
		final_rotation.c \
		get_target.c \
		calculate_cheapest.c \
		sort_three.c
		
		

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
DEPS := $(addprefix $(DEP_DIR)/, $(SRCS:%.c=%.d))

all: init-libft $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -I$(INC_DIRS) -I$(LIBFT_DIR) -c $< -o $@

init-libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) > /dev/null 2>&1 || \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(LIBFT_DIR) > /dev/null 2>&1 || \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -f $(LIBFT_DIR) > /dev/null 2>&1; \
		git rm -f $(LIBFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(LIBFT_DIR) > /dev/null 2>&1; \
	fi

$(LIBFT_LIB): init-libft
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS)

clean: remove-libft
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re init-libft remove-libft