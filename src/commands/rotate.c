/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:23:44 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 17:13:18 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stddef.h>

int	rotate(t_stack **s)
{
	t_stack	*last;

	if (!*s || !(*s)->next)
		return (0);
	last = *s;
	while (last->next)
		last = last->next;
	last->next = *s;
	*s = (*s)->next;
	last->next->next = NULL;
	return (1);
}

int	rotate_a(t_stack **a)
{
	if (!rotate(a))
		return (0);
	print_command("ra");
	return (1);
}

int	rotate_b(t_stack **b)
{
	if (!rotate(b))
		return (0);
	print_command("rb");
	return (1);
}
