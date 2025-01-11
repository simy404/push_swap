/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:23:36 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 03:28:18 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stddef.h>

int	reverse_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*s || !(*s)->next)
		return (0);
	last = *s;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *s;
	before_last->next = NULL;
	*s = last;
	return (1);
}

int	reverse_rotate_a(t_stack **a)
{
	if (!reverse_rotate(a))
		return (0);
	print_command("rra");
	return (1);
}

int	reverse_rotate_b(t_stack **b)
{
	if (!reverse_rotate(b))
		return (0);
	print_command("rrb");
	return (1);
}

int multi_revorse_rotate_b(t_stack **s, int count)
{
	while (count--)
	{
		if (!reverse_rotate_b(s))
			return (0);
	}
	return (1);
}

int multi_revorse_rotate_a(t_stack **s, int count)
{
	while (count--)
	{
		if (!reverse_rotate_a(s))
			return (0);
	}
	return (1);
}
