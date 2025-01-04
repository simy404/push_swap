/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:36 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 16:32:51 by hsamir           ###   ########.fr       */
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

void	printf_command(char *command);

#endif
