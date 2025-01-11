/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:23:40 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 17:20:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	push(t_stack **src, t_stack **dst)
{
	t_stack	*swp;

	if (!*src)
		return (0);
	swp = *src;
	*src = swp->next;
	swp->next = *dst;
	*dst = swp;
	return (1);
}

int	push_a(t_stack **a, t_stack **b)
{
	if (!push(b, a))
		return (0);
	print_command("pa");
	return (1);
}

int	push_b(t_stack **a, t_stack **b)
{
	if (!push(a, b))
		return (0);
	print_command("pb");
	return (1);
}

int	multi_push_a(t_stack **src, t_stack **dst, int count)
{
	while (count--)
	{
		if (!push_a(src, dst))
			return (0);
	}
	return (1);
}
