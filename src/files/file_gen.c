/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:36:39 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/01 20:38:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*file_gen_name(char *prefix, mode_t mode)
{
	int		count;
	char	*name;
	char	*suffix;

	count = 0;
	if (!file_exists(prefix) || file_hasperm(prefix, W_OK | R_OK))
		return (str_dup(prefix));
	while (true)
	{
		suffix = ft_itoa(count++);
		name = str_join(prefix, suffix);
		free(suffix);
		if (!file_exists(name) || file_hasperm(prefix, mode))
			return (name);
		free(name);
	}
	return (NULL);
}
