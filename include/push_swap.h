/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:36 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 17:59:34 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flag
{
	SORTED_DESC,
	SORTED_ASC
}					t_flag;

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}					t_stack;

int					swap_a(t_stack **a);
int					swap_b(t_stack **b);
int					push_a(t_stack **a, t_stack **b);
int					push_b(t_stack **a, t_stack **b);
int					multi_push_a(t_stack **src, t_stack **dst, int count);
int					rotate_a(t_stack **a);
int					rotate_b(t_stack **b);
int					reverse_rotate_a(t_stack **a);
int					reverse_rotate_b(t_stack **b);
int					multi_revorse_rotate_b(t_stack **s, int count);
int					multi_revorse_rotate_a(t_stack **s, int count);
int					print_error(char *error);

void				print_command(char *command);
void				clear_stack(t_stack **stack);

int					push_to_stack(t_stack **stack, int value);
int					is_stack_sorted(t_stack *stack, t_flag flag);
int					stack_size(t_stack *stack);

int					is_within_int_range(long number);
int					is_valid_number(char *str);
int					get_median(t_stack **stack, int size, t_stack **sec_stack);
long				ft_atol(const char *str);

int					stack_contains(t_stack *stack, int value);
int					parse_single_arguments(char *str, t_stack **stack);
int					parse_multiple_arguments(int argc, char **argv,
						t_stack **stack);

void				sort_top_three_asc(t_stack **s);
void				sort_three_asc(t_stack **s);
void				sort_top_three_desc(t_stack **s);
void				quick_sort(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

int					quick_sort_a(t_stack **stack_a, t_stack **stack_b,
						int size);
int					quick_sort_b(t_stack **stack_a, t_stack **stack_b,
						int size);

#endif
