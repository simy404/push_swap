/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:39:05 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 16:24:04 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

int	push_to_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last && last->next)
		last = last->next;
	last->next = new;
	return (1);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = 0;
}

int	is_stack_sorted(t_stack *stack, t_flag flag)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (flag == SORTED_ASC && stack->value > stack->next->value)
			return (0);
		if (flag == SORTED_DESC && stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
