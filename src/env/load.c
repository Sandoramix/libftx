/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:01:29 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 18:01:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*env_load(char **envp)
{
	t_list		*res;
	int			i;
	char		**split;
	int			len;

	i = -1;
	res = NULL;
	while (envp && envp[++i])
	{
		split = str_split_first(envp[i], '=');
		len = ft_memmtxlen(split);
		if (!split || len != 2
			|| !lst_addnew_tail(&res, split[1], split[0]))
			return (lst_printstr(res), ft_freemtx(split, len),
				lst_free(&res, free), NULL);
		if (len - 2 > 0)
			ft_freemtx(split + 2, len - 2);
		else
			free(split);
	}
	return (res);
}
