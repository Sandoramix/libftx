/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_printarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:54:15 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/20 09:26:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_int_printarr(int *arr, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i > 0)
			ft_printf(" ");
		ft_printf("[%d]", arr[i]);
	}
	ft_printf("\n");
}
