/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:37:24 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/15 16:49:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

int	main(void)
{
	const int		fd = open("mw.ber", O_RDONLY);
	char	*str = get_next_line(fd, false);

	ft_printf("%s\n", str);
	while (str)
	{
		free(str);
		str = get_next_line(fd, false);
		printf("%s\n", str);
	}
	free(str);
	return (0);
}
