/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writedouble_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:13:52 by odudniak          #+#    #+#             */
/*   Updated: 2024/08/20 14:43:52 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_writedouble_fd(double n, int precision, int fd)
{
	int			res = 0;
	double		after_point;
	int			i;

	if ((int)n == 0 && n < 0.0)
		res += ft_putchar_fd('-', fd);
	res += ft_putnbr_fd((int)n, fd);
	if (precision > 0)
		res += ft_putchar_fd('.', fd);
	after_point = n - (int)n;
	i = -1;
	while (++i < precision)
	{
		after_point *= 10.0;
		res += ft_putchar_fd(ft_iabs((int)after_point) + '0', fd);
		after_point -= (int)after_point;
	}
	return (res);
}
