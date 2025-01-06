/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:25:59 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/04 22:49:04 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../libft/libft.h"
#include <stdlib.h>

void free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int push_if_valid(char* str, t_stack **stack)
{
	if (!is_valid_number(str) || !is_within_int_range(str) || is_duplicate(*stack, ft_atoi(str)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (push_to_stack(stack, ft_atoi(str)));
}

int	parse_single_arguments(char* str, t_stack **stack)
{
	char **numbers;
	int i;

	i = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		if (!push_if_valid(numbers[i], stack))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

int	parse_multiple_arguments(int argc, char **argv, t_stack **stack)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (!push_if_valid(argv[i], stack))
			return (0);
		i++;
	}
	return (1);
}


