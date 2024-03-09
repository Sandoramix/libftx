/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parseargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:16:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/09 12:21:07 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdio.h>

typedef struct s_cmdparse
{
	bool		escaped;
	char		cur_quote;
	int			args_count;
	int			start;
	int			res_idx;
}	t_cmdparse;

int	count_arguments(const char *raw)
{
	t_cmdparse				info;
	int						i;

	info = (t_cmdparse){0};
	i = -1;
	while (raw && raw[++i])
	{
		if (raw[i] == ' ' && info.cur_quote == '\0' && !info.escaped)
		{
			if (i > 0 && raw[i - 1] != ' ')
				info.args_count++;
		}
		else if ((raw[i] == '\'' || raw[i] == '"') && !info.escaped)
			info.cur_quote = (int [2]){false, raw[i]}[info.cur_quote == raw[i]];
		else if (raw[i] == '\\' && !info.escaped)
			info.escaped = true;
		else
			info.escaped = false;
	}
	if (raw && raw[0] != '\0')
		info.args_count++;
	return (info.args_count);
}

char	**cmd_parse(char *raw)
{
	t_cmdparse			info;
	char				**res;
	int					i;

	if (!raw)
		return (NULL);
	info = (t_cmdparse){0};
	raw = str_trim(raw, " \n\t\n\v\f\r");
	if (!raw)
		return (NULL);
	info.args_count = count_arguments(raw);
	res = ft_calloc(info.args_count + 1, sizeof(char *));
	if (!res)
		return (free(raw), NULL);
	i = -1;
	while (raw[++i])
	{
		if (ft_isspace(raw[i]) && !info.cur_quote && !info.escaped)
		{
			if (i > 0 && !ft_isspace(raw[i - 1]))
			{
				res[info.res_idx] = my_substr(raw, info.start, i - 1);
				if (!res[info.res_idx])
					return (str_freemtx(res), free(raw), NULL);
				info.res_idx++;
			}
			info.start = i + 1;
		}
		else if (chr_isquote(raw[i]) && !info.escaped)
			info.cur_quote = (int [2]){raw[i], 0}[info.cur_quote == raw[i]];
		else if (raw[i] == '\\' && !info.escaped)
			info.escaped = true;
		else
			info.escaped = false;
	}
	if (raw[info.start] || raw)
	{
		res[info.res_idx] = str_dup(raw + info.start);
		if (!res[info.res_idx])
			return (free(raw), str_freemtx(res), NULL);
		info.res_idx++;
	}
	return (free(raw), res);
}
