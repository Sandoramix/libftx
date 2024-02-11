/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:55 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/11 20:10:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	file_exists(char *path, mode_t mode)
{
	return (access(path, F_OK) == 0);
}

int	file_open_or_create(char *path, mode_t mode)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return (open(path, mode));
	close(fd);
	return (open(path, mode));
}

bool	file_hasperm(char *path, mode_t perms)
{
	return (access(path, perms) == 0);
}
