#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

# define INT_MAX +2147483647
# define INT_MIN -2147483648
# define SUCCESS 1
# define FAILURE 0

/*A SUPPRIMER AVANT DE PUSH*/
# define ERR "Error : "
# define ERR_ARG "There are not enough arguments to start the program"
# define ERR_NUMBER "This list is not just made up of numbers"
# define ERR_LIMIT "One of the numbers exceeds the limits of an int"
# define ERR_DOUBLE "Your list of numbers contains duplicates"
# define ERR_EMPTY "Stack does not contain numbers"
# define ERR_EXEC "The executable is not called push_swap"
# define ERR_ONE "The stack contains only one number"
/*A SUPPRIMER AVANT DE PUSH*/

typedef struct s_params
{
	t_node		*elem;
	t_node		*best;
	int			count_actions_stack_a;
	int			count_actions_stack_b;
	int			min_move;
	int			total_moves;
	int			min_a;
	int			min_b;
	int			count_for_b;
}				t_params;

/*_______START___________*/
t_dlist		*init_stack(t_dlist *stack);

/*________PARSING________*/
int			check_input(int ac, char **av, t_dlist *stack_a);
int			check_order(t_dlist *stack_a);

/*_____SORT____*/
void		ft_push_swap(t_dlist *stack_a, t_dlist *stack_b, int ac);
void		case_of_two(t_dlist *stack_a, t_dlist *stack_b);
void		case_of_three(t_dlist *stack_a, t_dlist *stack_b);
void		case_of_four_and_five(t_dlist *stack_a, t_dlist *stack_b);

/*______utils______*/
int			compare_min(int a, int b);
int			check_min(t_dlist *stack, int len);
int			compare_max(int a, int b);
int			check_max(t_dlist *stack, int len);

/*_____ALGO____*/
t_dlist		*case_of_more(t_dlist *stack_a, t_dlist *stack_b);
t_dlist		*do_a_copy(t_dlist *stack_a);
t_dlist		*bubble_sort_cpy(t_dlist *cpy);
void		put_index_to_copy(t_dlist *cpy);
void		put_index_on_stack(t_dlist *stack_a, t_dlist *cpy);
int			check_true(t_dlist *stack);
void		put_false_on_stack_b(t_dlist *stack_a,
				t_dlist *stack_b, int size_sorted_part);
t_node		*calculate_best_actions(t_dlist *stack_a,
				t_dlist *stack_b, t_params *actions);
void		recup_move(t_params *actions);
void		do_actions(t_dlist *stack_a, t_dlist *stack_b, t_params *actions);
void		optimize_mins(t_dlist *stack_a, t_dlist *stack_b,
				t_params *actions);
int			return_absolute_value(int x);

/*_________OPERATIONS________*/
void		swap(t_dlist *stack, char *cmd);
void		rotate(t_dlist *stack, char *cmd);
void		rotate_both(t_dlist *stack_a, t_dlist *stack_b, char *cmd);
void		reverse_rotate(t_dlist *stack, char *cmd);
void		reverse_rotate_both(t_dlist *stack_a, t_dlist *stack_b, char *cmd);
void		push(t_dlist *src, t_dlist *dst, char *cmd);

/*_____utils____*/
void		command(void f(t_dlist *, char *), int iter,
				t_dlist *stack, char *cmd);
void		command_push(void f(t_dlist *, t_dlist *, char *),
				int iter, t_dlist *stack_a, t_dlist *stack_b, char *cmd);
void		command_both(void f(t_dlist *, t_dlist *), int iter,
				t_dlist *stack_a, t_dlist *stack_b);
int			smallest_on_top(t_dlist	*stack);
int			top_or_bottom(t_dlist *stack_a, int value);
int			check_top(t_dlist *stack_a, int x);
void		put_on_top(t_dlist *stack_a, int value);
void		put_on_stack_b(t_dlist *stack_a, t_dlist *stack_b);

#endif