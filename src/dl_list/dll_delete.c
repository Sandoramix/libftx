/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:56 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/17 17:48:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*dll_clearlist(t_dllist **head)
{
	t_dllist	*head_tmp;
	t_dllist	*curr;
	t_dllist	*prev;

	if (!head || !*head)
		return (NULL);
	prev = (*head)->prev;
	head_tmp = (*head)->next;
	free((*head)->val);
	free(*head);
	while (head_tmp && head_tmp != prev)
	{
		curr = head_tmp->next;
		free(head_tmp->val);
		free(head_tmp);
		head_tmp = curr;
	}
	*head = NULL;
	return (NULL);
}

t_dllist	*dll_delhead(t_dllist **head)
{
	t_dllist	*oldhead;

	if (!head || !*head)
		return (NULL);
	oldhead = *head;
	if (dll_size(*head) == 1)
		*head = NULL;
	else
	{
		*head = oldhead->next;
		(*head)->prev = oldhead->prev;
	}
	free(oldhead->val);
	free(oldhead);
	return (*head);
}

t_dllist	*dll_deltail(t_dllist **head)
{
	t_dllist	*oldtail;
	t_dllist	*pretail;

	if (!head || !*head)
		return (NULL);
	oldtail = dll_gettail(*head);
	if (dll_size(*head) == 1)
		*head = NULL;
	else
	{
		pretail = oldtail->prev;
		if (pretail && oldtail->next != pretail)
			pretail->next = oldtail->next;
		if (oldtail->next)
			oldtail->next->prev = pretail;
	}
	free(oldtail->val);
	free(oldtail);
	return (*head);
}
