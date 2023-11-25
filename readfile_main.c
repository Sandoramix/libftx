/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:37:24 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/24 20:45:12 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

int	main(void)
{
	int fd = open("empty", O_RDONLY);
	char **lines = ft_readfile(fd);
	int i = -1;
	while(lines && ++i < ft_memmtxlen(lines)){
		ft_printf("%s", lines[i]);
	}
	ft_freemtx((void **)lines, i - 1);
	return (0);
}
