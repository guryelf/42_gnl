NAME		= get_next_line.a
BONUS_NAME	= get_next_line_bonus.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

# ── mandatory ─────────────────────────────────────────────────────────────────
SRCS		= get_next_line.c \
		  get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

# ── bonus ──────────────────────────────────────────────────────────────────────
BONUS_SRCS	= get_next_line_bonus.c \
		  get_next_line_utils_bonus.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

# ── rules ──────────────────────────────────────────────────────────────────────
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Built $(NAME)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(BONUS_OBJS)
	@echo "Built $(BONUS_NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
