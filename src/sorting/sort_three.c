/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:18:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 01:51:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int is_sorted_order(t_stack **s, int a, int b, int c) {
	int da;
	int db;
	int dc;

	da = (*s)->value;
	db = (*s)->next->value;
	dc = (*s)->next->next->value;
	return !(da > db ^ a > b) && !(dc > db ^ c > b) && !(da > dc ^ a > c);
}

void	sort_top_three_asc(t_stack **s)
{
	if (is_sorted_order(s, 1, 2, 3))
		return ;
	if (is_sorted_order(s, 3, 1, 2) || is_sorted_order(s, 3, 2, 1))
		swap_a(s);
	if (is_sorted_order(s, 1, 3, 2) || is_sorted_order(s, 2, 3, 1))
	{
		rotate_a(s);
		swap_a(s);
		reverse_rotate_a(s);
	}
	if (is_sorted_order(s, 2, 1, 3))
		swap_a(s);
}

void	sort_three_asc(t_stack **s)
{
	if (is_sorted_order(s, 1, 2, 3))
		return ;
	if (is_sorted_order(s, 3, 1, 2) || is_sorted_order(s, 3, 2, 1))
		rotate_a(s);
	if (is_sorted_order(s, 1, 3, 2) || is_sorted_order(s, 2, 3, 1))
		reverse_rotate_a(s);
	if (is_sorted_order(s, 2, 1, 3))
		swap_a(s);
}

void	sort_top_three_desc(t_stack **s)
{
	if (is_sorted_order(s, 3, 2, 1))
		return ;
	if (is_sorted_order(s, 1, 2, 3) || is_sorted_order(s, 1, 3, 2))
		swap_b(s);
	if (is_sorted_order(s, 3, 1, 2) | is_sorted_order(s, 2, 1, 3))
	{
		rotate_b(s);
		swap_b(s);
		reverse_rotate_b(s);
	}
	if (is_sorted_order(s, 2, 3, 1))
		swap_b(s);
}
