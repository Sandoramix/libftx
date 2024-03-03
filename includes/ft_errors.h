/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:47:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/03 23:19:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

typedef enum e_errorcode
{
	ERR_DEFAULT,
	ERR_INVALID_ARGC,
	ERR_MALLOC,
	ERR_FILE_NOT_FOUND,
	ERR_FILE_PERMISSION_DENIED,
	ERR_ENV_LOAD,
	ERR_PATH_LOAD,
	ERR_FORK,
	ERR_PIPE,
	ERR_DUP2
}	t_errorcode;

#endif
