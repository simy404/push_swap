/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:39:05 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 22:49:14 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

int	push_to_stack(t_stack **stack, int value)
{
	t_stack *new;
	t_stack *last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->flag = UNSORTED;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while(last && last->next)
		last = last->next;
	last->next = new;
	return (1);
}
