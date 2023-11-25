/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrmtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:09:22 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/25 15:54:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrmtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
	{
		ft_putstr_fd("mtx[", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("]: ", 1);
		ft_putstr_fd(mtx[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
