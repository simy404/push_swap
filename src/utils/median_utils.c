/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:00:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 16:23:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

int	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	get_median(t_stack **stack, int size)
{
	int		*arr;
	t_stack	*tmp;
	int		c;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		//ft_clear_stacks() //TODO implement this function
		exit(1);
	}
	c = size;
	tmp = *stack;
	while (size)
	{
		arr[--size] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, c);
	c = arr[c / 2];
	free(arr);
	return (c);
}
