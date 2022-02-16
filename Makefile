NAME1	= push_swap

NAME2	= checker
#
CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= main.c sort.c operations.c score.c check.c smal_sort.c small_sort_utils.c calls.c int_sort.c sort500.c error.c

SRC2	= checker.c sort.c operations.c score.c check.c smal_sort.c small_sort_utils.c calls.c int_sort.c operations2.c sort500.c error.c
#
OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))
#
HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME1)

bonus: $(LIBFT) ./includes/libft/libft.a $(NAME2)

FORCE:		;

LIBFT		= ./includes/libft/libft.a

$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME2): $(OBJS2) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS2) $(LIB_BINARY) -o $@

$(NAME1): $(OBJS1) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@



clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2) 
	make -C ./includes/libft fclean

re: fclean all