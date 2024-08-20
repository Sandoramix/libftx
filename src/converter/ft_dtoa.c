/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:18:31 by odudniak          #+#    #+#             */
/*   Updated: 2024/08/20 14:41:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double n, int precision)
{
	double		after_point;
	int			i;
	char		*res;

	res = ft_itoa((int)n);
	if (!res)
		return (NULL);
	if (precision > 0)
		res = str_pushchar(res, '.');
	if (!res)
		return (NULL);
	after_point = (n - (int)n) * (int [2]){1.0, -1.0}[n < 0.0];
	i = -1;
	while (++i < precision)
	{
		after_point *= 10.0;
		res = str_pushchar(res, ft_iabs((int)after_point) + '0');
		if (!res)
			return (NULL);
		after_point -= (int)after_point;
	}
	if ((int)n == 0 && n < 0.0)
		res = str_pad(res, '-', str_ilen(res) + 1, true);
	return (res);
}
