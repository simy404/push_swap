/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:48:57 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/08 23:48:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void sort_stack(t_stack **stack)
{
	int size;

	if(is_stack_sorted(*stack, SORTED_ASC))
		return ;
	size = stack_size(*stack);
	if(size == 2)
	{
		if((*stack)->value > (*stack)->next->value)
			swap_a(stack);
	}
	else if(size == 3)
		sort_three_asc(stack);
	else
		quick_sort(stack);
}
