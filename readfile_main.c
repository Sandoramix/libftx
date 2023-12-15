/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:37:24 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/15 17:05:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

int	main(void)
{
	const int		fd = open("mw.ber", O_RDONLY);
	char		**lines = ft_readfile(fd, false);
	int i = -1;
	while(lines && ++i < ft_memmtxlen(lines)){
		ft_printf("%s\n", lines[i]);
	}
	ft_freemtx((void **)lines, ft_memmtxlen(lines));
	return (0);
}
