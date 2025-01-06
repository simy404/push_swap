/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:36 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 22:48:05 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flag
{
	UNSORTED,
	SORTED_DESC,
	SORTED_ASC
}	t_flag;

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	t_flag			flag;
}	t_stack;

int	swap_a(t_stack **a);
int	swap_b(t_stack **b);
int	push_a(t_stack **a, t_stack **b);
int	push_b(t_stack **a, t_stack **b);
int	rotate_a(t_stack **a);
int	rotate_b(t_stack **b);
int	reverse_rotate_a(t_stack **a);
int	reverse_rotate_b(t_stack **b);

void	print_command(char *command);
void	clear_stack(t_stack **stack);
long	ft_atol(const char *str);
int		push_to_stack(t_stack **stack, int value);

int		is_within_int_range(char* str);
int		is_valid_number(char* str);
int		is_duplicate(t_stack *stack, int value);
int		parse_single_arguments(char* str, t_stack **stack);
int		parse_multiple_arguments(int argc, char **argv, t_stack **stack);

#endif
