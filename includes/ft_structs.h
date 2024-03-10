/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:53:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 09:29:40 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
# include <libft.h>

/**
 * @brief `List` data structure
 * @param val value of the node.
 * @param key additional attribute which could be used as search param.
 * @param next pointer of the next node.
 * @param prev pointer of the previous node.
 * @param _is_lis (used on list of numbers) is the node a part of LIS ?
 * (Longest Increasing sequence).
 */
typedef struct s_list
{
	void				*val;
	void				*key;

	struct s_list		*next;
	struct s_list		*prev;

	bool				*_is_lis;
	int					*_lis_max;
}	t_list;

typedef struct s_dllist
{
	int					*val;

	struct s_dllist		*next;
	struct s_dllist		*prev;

	bool				*_is_lis;
	int					*_lis_max;
}	t_dllist;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_counter
{
	int		i;
	int		j;
	int		k;
}	t_counter;

typedef struct s_cmdparse
{
	bool		escaped;
	char		cur_quote;
	int			args_count;
	int			start;
	int			res_idx;
}	t_cmdparse;

typedef enum e_status
{
	OK,
	KO
}	t_status;

#endif