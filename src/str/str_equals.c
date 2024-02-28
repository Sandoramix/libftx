/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:49:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	str_equals(char *a, char *b)
{
	if (a == b)
		return (true);
	if (!a || !b)
		return (false);
	return (!str_cmp(a, b));
}
