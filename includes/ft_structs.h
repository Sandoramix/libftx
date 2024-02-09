/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:53:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:59:29 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
# include <libft.h>

/**
 * @brief `List` data structure
 * @param content `void *`
 * @param next `s_list *`
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dllist
{
	int					*val;
	struct s_dllist		*next;
	struct s_dllist		*prev;
}	t_dllist;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif