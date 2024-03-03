/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_errcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:23:24 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 17:54:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	errswitch(t_errorcode code)
{
	if (code == ERR_MALLOC)
		return (ft_perror("Malloc allocation failed."));
	if (code == ERR_INVALID_ARGC)
		return (ft_perror("Invalid number of arguments."));
	if (code == ERR_FILE_NOT_FOUND)
		return (ft_perror("File not found."));
	if (code == ERR_FILE_PERMISSION_DENIED)
		return (ft_perror("File permissions denied."));
	if (code == ERR_ENV_LOAD)
		return (ft_perror("Failed loading ENV variables."));
	if (code == ERR_PATH_LOAD)
		return (ft_perror("Failed loading \"PATH\" from env."));
	if (code == ERR_FORK)
		return (ft_perror("Fork failure."));
	return (ft_perror("."));
}

int	pf_errcode(t_errorcode code)
{
	int	len;

	len = ft_perror("Error");
	if (code != ERR_DEFAULT)
		len += ft_perror(":\t") + errswitch(code);
	return (len + ft_perror("\n"));
}
