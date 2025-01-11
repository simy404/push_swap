/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:11:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 03:58:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "libft/libft.h"

int main(int argc, char** argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int error;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if(argc == 2)
		error = parse_single_arguments(argv[1], &stack_a);
	else
		error = parse_multiple_arguments(argc, argv, &stack_a);
	if (!error)
	{
		clear_stack(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	clear_stack(&stack_a);
	return (1);
}
