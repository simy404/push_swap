/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:18:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/10 15:00:04 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_top_three_asc(t_stack **s)
{
	if ((*s)->value < (*s)->next->value && (*s)->next->value < (*s)->next->next->value) // 1 2 0
		return ;
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
	if ((*s)->value < (*s)->next->value && (*s)->next->value < (*s)->next->next->value)
		return ;
	if ((*s)->value > (*s)->next->value && (*s)->value > (*s)->next->next->value)
		rotate_a(s);
	if ((*s)->next->value > (*s)->value && (*s)->next->value > (*s)->next->next->value)
		reverse_rotate_a(s);
	if ((*s)->value > (*s)->next->value && (*s)->value  < (*s)->next->next->value)
		swap_a(s);
	// print_command("test3\n");

}

void	sort_top_three_desc(t_stack **s)
{
	if ((*s)->value > (*s)->next->value && (*s)->next->value > (*s)->next->next->value)
		return ;
	if ((*s)->value < (*s)->next->value && (*s)->value < (*s)->next->next->value)
		swap_b(s);
	if ((*s)->next->value < (*s)->value && (*s)->next->value < (*s)->next->next->value)
	{
		rotate_b(s);
		swap_b(s);
		reverse_rotate_b(s);
	}
	if ((*s)->value < (*s)->next->value && (*s)->value > (*s)->next->next->value)
		swap_b(s);
}

int is_sorted_order(t_stack **s, int a, int b, int c) {
	int da;
	int db;
	int dc;

	da = (*s)->value;
	db = (*s)->next->value;
	dc = (*s)->next->next->value;
    return !(da > db ^ a > b) && !(dc > db ^ c > b) && !(da > dc ^ a > c);
}
