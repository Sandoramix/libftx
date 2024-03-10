/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parseargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:16:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/10 09:12:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdio.h>

static int	count_arguments(const char *raw)
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

static bool	cmdparse_init(t_cmdparse *data, char **raw, char ***res, int *i)
{
	if (!raw)
		return (false);
	*data = (t_cmdparse){0};
	*raw = str_trim(*raw, " \n\t\n\v\f\r");
	if (!*raw)
		return (false);
	data->args_count = count_arguments(*raw);
	*res = ft_calloc(data->args_count + 1, sizeof(char *));
	if (!*res)
		return (free(*raw), false);
	*i = -1;
	return (true);
}

static char	**checklast(t_cmdparse info, char *raw, char **res, int i)
{
	i--;
	if (raw[info.start])
	{
		res[info.res_idx] = my_substr(raw, info.start
				+ chr_isquote(raw[info.start]), i - chr_isquote(raw[i]));
		if (!res[info.res_idx])
			return (free(raw), str_freemtx(res), NULL);
		info.res_idx++;
	}
	free(raw);
	return (res);
}

char	**cmd_parse(char *raw)
{
	t_cmdparse			info;
	char				**res;
	int					i;

	if (!cmdparse_init(&info, &raw, &res, &i))
		return (NULL);
	while (raw[++i])
	{
		if (ft_isspace(raw[i]) && !info.cur_quote && !info.escaped)
		{
			if (i > 0 && !ft_isspace(raw[i - 1]))
			{
				res[info.res_idx++] = my_substr(raw, info.start + chr_isquote(\
				raw[info.start]), i - 1 - chr_isquote(raw[info.start]));
				if (!res[info.res_idx - 1])
					return (str_freemtx(res), free(raw), NULL);
			}
			info.start = i + 1;
		}
		else if (chr_isquote(raw[i]) && !info.escaped)
			info.cur_quote = (int [2]){raw[i], 0}[info.cur_quote == raw[i]];
		else
			info.escaped = (raw[i] == '\\' && !info.escaped);
	}
	return (checklast(info, raw, res, i));
}
