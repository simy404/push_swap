/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:57:14 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/11 16:25:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

void	print_command(char *command)
{
	ft_putendl_fd(command, 1);
}

int	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	return (0);
}
