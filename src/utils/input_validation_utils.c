/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:28:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 22:46:05 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../libft/libft.h"
#include <limits.h>

int is_valid_number(char* str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int is_within_int_range(char* str)
{
	long number;

	number = ft_atol(str);
	return (number >= INT_MIN && number <= INT_MAX);
}
