/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 15:43:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H
# include <libft.h>
// TODO ADD DOCS

typedef struct s_intarr
{
	int		*arr;
	int		size;
}	t_intarr;

typedef struct s_intmtx
{
	int		**mtx;
	int		size;
}	t_intmtx;

int				int_imin(int n1, int n2);

int				*intarr_push(t_intarr *data, int val);
int				**intmtx_push(t_intmtx *data, int *val);

int				*intarr_insert(t_intarr *data, int val, int idx);
int				**intmtx_insert(t_intmtx *data, int *val, int idx);

int				intmtx_idxof(t_intmtx data, int *val);
int				intarr_idxof(t_intarr data, int val);

void			*intarr_clear(t_intarr data);
void			*intmtx_clear(t_intmtx data);
//!-------------------------INTEGERS----------------------------
// TODO UPDATE ME

void			int_printarr(t_intarr data);
void			intp_printarr(t_intmtx data);
int				ft_int_minmax_idx(t_intarr data, bool find_min);
int				ft_intcmp(int n1, int n2);
#endif