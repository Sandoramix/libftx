/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:47:06 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/29 07:54:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

typedef enum e_errorcode
{
	ERROR_DEFAULT,
	ERROR_MALLOC,
	ERROR_FILE_NOT_FOUND,
	ERROR_FILE_NOT_ACCESSIBLE,
}	t_errorcode;

#endif

