/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:45:45 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/08 23:45:45 by hsamir           ###   ########.fr       */
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
int quick_sort_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	// int count;
	int pivot;
	int rc;
	int a_new_size;
	rc = 0;
	// count = size;
	if (size == 3)
	{
		sort_top_three_desc(stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		return (1);
	}
	else if (size == 2)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		return (1);
	}
	else if (size == 1)
	{
		push_a(stack_a, stack_b);
		return (1);
	}
	pivot = get_median(stack_b, size);

	a_new_size = size / 2 + size % 2;
	while (a_new_size)
	{
		if ((*stack_b)->value >= pivot)
		{
			push_a(stack_a, stack_b);
			a_new_size--;
		}
		else
		{
			rotate_b(stack_b);
			rc++;
		}
	}
	while (rc--)
		reverse_rotate_b(stack_b);
	quick_sort_a(stack_a, stack_b, size / 2 + size % 2);
	quick_sort_b(stack_a, stack_b, size / 2);;
	return (1);
}
int quick_sort_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int pivot;
	int rc;
	int size_a;
	int count;
	int a_new_size;
	rc= 0;
	count = size;
	size_a = stack_size(*stack_a);
	if (size == 3)
	{
		if (size_a == 3)
			sort_three_asc(stack_a);
		else
			sort_top_three_asc(stack_a);
		return (1);
	}
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
		return (1);
	}
	else if (size == 1)
		return (1);
	pivot = get_median(stack_a, size);
	a_new_size = size / 2 + size % 2;
	// printf("pivot a : %d\n", pivot);
	while (count-- && a_new_size)
	{
		if ((*stack_a)->value < pivot)
		{
			push_b(stack_a, stack_b);
			a_new_size--;
		}
		else
		{
			rotate_a(stack_a);
			rc++;
		}
	}
	while (rc--)
		reverse_rotate_a(stack_a);
	quick_sort_a(stack_a, stack_b, size / 2 + size % 2);
	quick_sort_b(stack_a, stack_b, size / 2);
	return (1);
}




