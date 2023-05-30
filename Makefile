NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = abs.c check_duplicate.c check_sort.c deq_a_loc.c deq_b_loc.c \
		deq_basic_operation.c deq_command1.c deq_command2.c deq_get_value.c \
		deq_hardcoding.c deq_indexing.c deq_init.c deq_setting.c deq_size.c \
		deq_sort.c deq_utils.c find_min_loc.c ft_atoi.c ft_error.c ft_split.c \
		greedy_logic.c iterate_rotation.c main.c check_arg.c make_arg_arr.c
SRCS_BONUS = abs_bonus.c check_duplicate_bonus.c check_sort_bonus.c  \
		deq_basic_operation_bonus.c deq_command1_bonus.c deq_command2_bonus.c deq_get_value_bonus.c \
		deq_indexing_bonus.c deq_init_bonus.c  deq_size_bonus.c \
		deq_utils_bonus.c ft_atoi_bonus.c ft_error_bonus.c ft_split_bonus.c \
		iterate_rotation_bonus.c main_bonus.c ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c \
		check_arg_bonus.c make_arg_arr_bonus.c KO_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
RM = rm
RMFLAGS = -f

ifdef BONUS
$(BONUS_NAME): $(OBJS_BONUS)
	 $(CC) $(CFLAGS) $^ -o $@ 
else
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
endif

all: $(NAME)

bonus :
	make BONUS=1

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS) 

fclean: 
	make clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME) 

re: 
	make fclean
	make all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: all clean fclean re bonus