/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:45:45 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 03:42:20 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int sort_array(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}
int get_median(t_stack **stack, int size)
{
	int *arr;
	t_stack *tmp;
	int c;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	c = size;
	tmp = *stack;
	while(size)
	{
		arr[--size] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, c);
	c = arr[c / 2];
	free(arr);
	return (c);
}
int handle_less_than_three_b(t_stack **stack_a, t_stack **stack_b, int size)
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
		return (multi_push_a(stack_a, stack_b , 2));
	}
	else
		return (push_a(stack_a, stack_b));
}

int handle_less_than_three_a(t_stack **stack_a, int size)
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

int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int pivot;
	int rotate_count;
	int size_half;

	rotate_count = 0;
	if (size <= 3)
		return (handle_less_than_three_b(stack_a, stack_b, size));
	pivot = get_median(stack_b, size);
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
	multi_revorse_rotate_b(stack_b, rotate_count);
	quick_sort_a(stack_a, stack_b, size / 2 + size % 2);
	quick_sort_b(stack_a, stack_b, size / 2);
	return (1);
}
int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int pivot;
	int rotate_count;
	int size_half;

	rotate_count = 0;
	if (size <= 3)
		return (handle_less_than_three_a(stack_a, size));
	pivot = get_median(stack_a, size);
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
	multi_revorse_rotate_a(stack_a, rotate_count);
	quick_sort_a(stack_a, stack_b, size / 2 + size % 2);
	quick_sort_b(stack_a, stack_b, size / 2);
	return (1);
}




