/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:11:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 16:30:23 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

int dev_test()
{
	t_stack *stack = NULL;
    t_stack node1 = {NULL, 1, UNSORTED};
    t_stack node2 = {NULL, 2, UNSORTED};
    t_stack node3 = {NULL, 3, UNSORTED};
	t_stack *src = NULL;
	stack = &node1;
	node1.next = &node2;
	node2.next = &node3;
	// rotat(&stack);
	reverse_rotate_a(&stack);
		reverse_rotate_a(&stack);
		reverse_rotate_a(&stack);


	print_stack(stack);
	printf("-----\n");

    return 0;
}

int main(int ac, char** av)
{
	// if (ac < 2)
	// 	return (0);
	dev_test();
	//TODO : the main function is going to be wrote here after i get the subject
	return (1);
}
