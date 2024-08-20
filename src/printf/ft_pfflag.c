/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:18 by odudniak          #+#    #+#             */
/*   Updated: 2024/08/20 14:35:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_pfflag	pf_parseflag(t_pfflag flag)
{
	size_t	rawlen;
	int		d_i;

	rawlen = str_ulen(flag.flag);
	flag.convert = false;
	flag.wzeros = false;
	flag.prec = (int [2]){-1, 2}[flag.type == PF_DOUBLE];
	flag.wminus = !!str_chr(flag.flag, '-');
	flag.wplus = !!str_chr(flag.flag, '+');
	flag.wspaces = !!str_chr(flag.flag, ' ') && !flag.wplus;
	flag.isupper = chr_tolower(flag.flag[rawlen - 1]) != flag.flag[rawlen - 1];
	flag.zero = false;
	if (str_chr(flag.flag, '#'))
		flag.convert = true;
	d_i = str_ilen(flag.flag) - 2;
	while (d_i > 0 && (chr_isdigit(flag.flag[d_i]) || flag.flag[d_i] == '.'))
		d_i--;
	flag.width = ft_atoi(flag.flag + d_i + 1);
	if (str_chr(flag.flag, '.'))
		flag.prec = ft_atoi(str_chr(flag.flag, '.') + 1);
	flag.wprec = flag.prec != -1;
	if (str_chr(flag.flag, '0'))
		flag.wzeros = !flag.wprec
			&& !chr_isdigit(*(str_chr(flag.flag, '0') - 1));
	return (flag);
}

static t_pfflag	pf_fillempty(t_pfflag flag)
{
	flag.res = NULL;
	flag.reslen = 0;
	flag.flag = NULL;
	flag.convert = false;
	flag.wzeros = false;
	flag.width = 0;
	flag.prec = (int [2]){-1, 2}[flag.type == PF_DOUBLE];
	flag.wminus = false;
	flag.minus = false;
	flag.wplus = false;
	flag.wspaces = false;
	flag.wprec = false;
	flag.isupper = false;
	flag.zero = false;
	flag.llen = 0;
	flag.rlen = 0;
	return (flag);
}

t_pfflag	pf_getflag(char *str, int start, int end)
{
	const char		*valid_ids[] = {"di", "p", "xX", "u", "%", "c", "s", "f"};
	const t_pftype	ids_value[] = {PF_INT, PF_POINTER, PF_HEX, PF_UINT,
		PF_ESCAPE, PF_CHAR, PF_STR, PF_DOUBLE};
	t_pfflag		flag;
	int				i;

	flag = (t_pfflag){0};
	flag.simple = end - 1 == start;
	flag._str = str;
	flag._start = start;
	flag._end = end;
	i = -1;
	while (++i < 8)
	{
		if (str_chr(valid_ids[i], str[end]))
			flag.type = ids_value[i];
		if (str_chr(valid_ids[i], str[end]))
			break ;
	}
	if (!valid_ids[i])
		flag.type = PF_UNKNOWN;
	if (flag.simple)
		return (pf_fillempty(flag));
	flag.flag = str_lensubstr(str, start, end - start + 1);
	return (pf_parseflag(flag));
}
