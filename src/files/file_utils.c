/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:55 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:18:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	file_exists(char *path)
{
	return (access(path, F_OK) == 0);
}

int	file_open_or_create(char *path, mode_t mode)
{
	int	fd;

	fd = open(path, O_CREAT | mode, 000644);
	if (fd < 0)
		return (open(path, mode));
	close(fd);
	return (open(path, mode));
}

bool	file_hasperm(char *path, mode_t perms)
{
	return (access(path, perms) == 0);
}
