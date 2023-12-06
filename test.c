/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:30:37 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/06 18:31:01 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	ft_printf(ft_boolstr(ft_strendswith(av[1], av[2])));
	return (0);
}
