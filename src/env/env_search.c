/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:00:11 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/28 19:18:26 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*env_search(t_list *envlist, char *key)
{
	if (!envlist || !key)
		return (NULL);
	return (lst_findbykey(envlist, key,
			(bool (*)(void *a, void *b))str_equals));
}
