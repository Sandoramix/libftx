/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:09:44 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/25 15:09:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"

char	**ft_readfile(int fd, bool keep_nl)
{
	char	**res;
	char	**tmp;
	int		linecount;

	if (fd < 0)
		return (NULL);
	linecount = 0;
	res = ft_calloc(1, sizeof(char *));
	while (linecount == 0 || res[linecount - 1])
	{
		tmp = ft_calloc(++linecount + 1, sizeof(char *));
		tmp[linecount] = NULL;
		tmp[linecount - 1] = get_next_line(fd, keep_nl);
		ft_memmtxcpy((void **)tmp, (void **)res, linecount - 1);
		free(res);
		res = tmp;
	}
	return (res);
}
