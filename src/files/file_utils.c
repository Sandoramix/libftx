/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:55 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 20:41:18 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	file_isdir(char *path)
{
	int		fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	file_exists(char *path)
{
	return (!file_isdir(path) && access(path, F_OK) == 0);
}

int	file_open(char *path, mode_t mode)
{
	if (file_isdir(path))
		return (-1);
	return (open(path, mode));
}

int	file_open_or_create(char *path, mode_t mode)
{
	int	fd;

	fd = open(path, O_CREAT | mode, 0644);
	if (fd == -1)
		return (open(path, mode));
	close(fd);
	return (file_open(path, mode));
}

bool	file_hasperm(char *path, mode_t perms)
{
	return (!file_isdir(path) && !access(path, perms));
}
