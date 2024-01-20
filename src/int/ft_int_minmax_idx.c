/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_maxidx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:40:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/20 08:45:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_minmax_idx(int *arr, int size, bool find_min)
{
	int		res;
	int		i;

	if (size <= 0)
		return (-1);
	res = 0;
	i = 0;
	while (++i < size)
		if ((find_min && arr[res] > arr[i]) || (!find_min && arr[res] < arr[i]))
			res = i;
	return (res);
}
