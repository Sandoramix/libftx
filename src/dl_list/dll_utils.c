/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:48 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/14 15:42:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	dll_size(t_dllist *head)
{
	t_dllist	*res;
	int			i;

	if (!head)
		return (0);
	i = 1;
	res = head->next;
	while (res && res != head)
	{
		i++;
		res = res->next;
	}
	return (i);
}

void	dll_printlist(t_dllist *head)
{
	t_dllist	*tmp;
	int			i;

	i = -1;
	if (!head)
	{
		ft_printf("NULL\n");
		return ;
	}
	ft_printf(COLOR_CYAN"[%d]:\t%d\n", ++i, *(head->val));
	tmp = head->next;
	while (tmp)
	{
		ft_printf(COLOR_CYAN"[%d]:\t%d\n", ++i, *(tmp->val));
		tmp = tmp->next;
	}
	ft_printf(""CR);
}

void	dll_printrevlist(t_dllist *head)
{
	t_dllist	*tail;
	t_dllist	*tmp;
	int			i;

	i = dll_size(head);
	if (!head)
	{
		ft_printf("NULL\n");
		return ;
	}
	tail = dll_gettail(head);
	tmp = tail;
	ft_printf("[%d]:\t%d\n", --i, *(tmp->val));
	tmp = tmp->prev;
	while (tmp && tmp != tail)
	{
		ft_printf("[%d]:\t%d\n", --i, *(tmp->val));
		tmp = tmp->prev;
	}
}

t_dllist	*dll_gettail(t_dllist *head)
{
	t_dllist	*tmp;

	if (!head || !head ->next)
		return (head);
	tmp = head->next;
	while (tmp->next && tmp->next != head)
		tmp = tmp->next;
	return (tmp);
}
