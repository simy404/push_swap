/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:23:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 16:36:50 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap(t_stack **s)
{
	t_stack	*swp;

	if (!(*s) || !(*s)->next)
		return (0);
	swp = (*s)->next;
	(*s)->next = swp->next;
	swp->next = *s;
	*s = swp;
	return (1);
}

int	swap_a(t_stack **a)
{
	if (!swap(a))
		return (0);
	printf_command("sa");
	return (1);
}

int	swap_b(t_stack **b)
{
	if (!swap(b))
		return (0);
	printf_command("sb");
	return (1);
}

int	swap_both(t_stack **a, t_stack **b)
{
	if (!swap(a) || !swap(b))
		return (0);
	printf_command("ss");
	return (1);
}
