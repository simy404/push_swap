/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:45:45 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 18:04:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

int	handle_less_than_three_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 3)
	{
		sort_top_three_desc(stack_b);
		return (multi_push_a(stack_a, stack_b, 3));
	}
	else if (size == 2)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			swap_b(stack_b);
		return (multi_push_a(stack_a, stack_b, 2));
	}
	else
		return (push_a(stack_a, stack_b));
}

int	handle_less_than_three_a(t_stack **stack_a, int size)
{
	if (size == 3)
	{
		if (stack_size(*stack_a) == 3)
			sort_three_asc(stack_a);
		else
			sort_top_three_asc(stack_a);
		return (1);
	}
	else if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
		return (swap_a(stack_a));
	return (1);
}

int	quick_sort_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot;
	int	rotate_count;
	int	size_half;

	rotate_count = 0;
	if (size <= 3)
		return (handle_less_than_three_b(stack_a, stack_b, size));
	pivot = get_median(stack_b, size, stack_a);
	size_half = size / 2 + size % 2;
	while (size_half)
	{
		if ((*stack_b)->value >= pivot && size_half--)
			push_a(stack_a, stack_b);
		else
		{
			rotate_b(stack_b);
			rotate_count++;
		}
	}
	if (stack_size(*stack_b) > size / 2)
		multi_revorse_rotate_b(stack_b, rotate_count);
	return (quick_sort_a(stack_a, stack_b, size / 2 + size % 2)
		&& quick_sort_b(stack_a, stack_b, size / 2));
}

int	quick_sort_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot;
	int	rotate_count;
	int	size_half;

	rotate_count = 0;
	if (size <= 3)
		return (handle_less_than_three_a(stack_a, size));
	pivot = get_median(stack_a, size, stack_b);
	size_half = size / 2;
	while (size_half)
	{
		if ((*stack_a)->value < pivot && size_half--)
			push_b(stack_a, stack_b);
		else
		{
			rotate_a(stack_a);
			rotate_count++;
		}
	}
	if (stack_size(*stack_a) > (size / 2 + size % 2))
		multi_revorse_rotate_a(stack_a, rotate_count);
	return (quick_sort_a(stack_a, stack_b, size / 2 + size % 2)
		&& quick_sort_b(stack_a, stack_b, size / 2));
}
