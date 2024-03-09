/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:16:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/09 12:25:51 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_chr(const char *s, int c)
{
	size_t	s_len;
	char	*s_p;
	size_t	i;

	s_len = str_ulen(s);
	s_p = (char *)s;
	i = 0;
	while (i <= s_len)
	{
		if (s_p[i] == (char)c)
			return (&s_p[i]);
		i++;
	}
	return (NULL);
}

// TODO move me somewhere else
bool	str_isblank(char *s)
{
	int		len;

	if (!s)
		return (true);
	s = str_trim(s, " \n\t\n\v\f\r");
	if (!s)
		return (-1);
	len = str_ilen(s);
	free(s);
	return (!len);
}
