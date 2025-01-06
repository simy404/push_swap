/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:11:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 22:04:52 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "libft/libft.h"

#include <stdio.h> //TODO : this library will be deleted after the project is done
int print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	return 0;
}


int main(int argc, char** argv)
{
	t_stack *stack_a;
	// t_stack *stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc < 2)
		return (0);
	if(argc == 2)
		parse_single_arguments(argv[1], &stack_a);
	else
		parse_multiple_arguments(argc, argv, &stack_a);
	print_stack(stack_a);
	clear_stack(&stack_a);
	return (1);
}
