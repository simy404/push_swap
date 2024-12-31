/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:36 by hsamir            #+#    #+#             */
/*   Updated: 2024/12/30 17:05:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flag
{
    UNSORTED,
    SORTED,
	BELONGS_TO_A,
	BELONGS_TO_B
}   t_flag;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int	value;
	t_flag flag;
}	t_stack;

#endif
