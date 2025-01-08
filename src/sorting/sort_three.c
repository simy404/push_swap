/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:18:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/08 22:18:22 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_top_three_asc(t_stack **s)
{
	if ((*s)->value > (*s)->next->value && (*s)->value > (*s)->next->next->value)
		swap_a(s);
	if ((*s)->next->value > (*s)->value && (*s)->next->value > (*s)->next->next->value)
	{
		rotate_a(s);
		swap_a(s);
		reverse_rotate_a(s);
	}
	if ((*s)->value > (*s)->next->value && (*s)->value < (*s)->next->next->value)
		swap_a(s);
}

void	sort_three_asc(t_stack **s)
{
	if ((*s)->value > (*s)->next->value && (*s)->value > (*s)->next->next->value)
		rotate_a(s);
	if ((*s)->next->value > (*s)->value && (*s)->next->value > (*s)->next->next->value)
		reverse_rotate_a(s);
	if ((*s)->value > (*s)->next->value && (*s)->value  < (*s)->next->next->value)
		swap_a(s);
}

void	sort_top_three_desc(t_stack **s)
{
	if ((*s)->value < (*s)->next->value && (*s)->value < (*s)->next->next->value)
		swap_a(s);
	if ((*s)->next->value < (*s)->value && (*s)->next->value < (*s)->next->next->value)
	{
		rotate_a(s);
		swap_a(s);
		reverse_rotate_a(s);
	}
	if ((*s)->value < (*s)->next->value && (*s)->value > (*s)->next->next->value)
		swap_a(s);
}
