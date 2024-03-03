/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:43 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/04 00:11:10 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H
# include <libft.h>

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

/**
 * @brief Get the lowest number between the two given
 *
 * @param n1 First number
 * @param n2 Second number
 * @return
 */
int				int_imin(int n1, int n2);

void			*int_freemtx(int **mtx, int rows);

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