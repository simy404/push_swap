/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:48:57 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 16:18:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_stack_sorted(*stack_a, SORTED_ASC))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
	}
	else if (size == 3)
		sort_three_asc(stack_a);
	else
		quick_sort_a(stack_a, stack_b, size);
}
