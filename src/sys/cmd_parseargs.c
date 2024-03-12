/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parseargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:16:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/12 21:09:27 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdio.h>
// TODO REFACTOR ME
static int	count_arguments(const char *raw)
{
	t_cmdparse				info;
	int						i;

	info = (t_cmdparse){0};
	i = -1;
	while (raw && raw[++i])
	{
		if (raw[i] == ' ' && !info.outside_quote && !info.escaped && !info.inside_quote)
		{
			if (i > 0 && raw[i - 1] != ' ')
				info.args_count++;
		}
		else if (chr_isquote(raw[i]) && !info.escaped && !info.outside_quote)
		{
			if (!info.inside_quote)
			{
				info.outside_quote = raw[i];
				info.inside_quote = true;
			}
			else if (raw[i] == info.outside_quote)
			{
				info.inside_quote = false;
				info.outside_quote = 0;
			}
		}
		else if (raw[i] == '\\' && !info.escaped && chr_isquote(info.outside_quote) && chr_isquote(raw[i + 1]))
		{
			info.escaped = true;
			i++;
		}
		else
			info.escaped = raw[i] == '\\' && !info.escaped && chr_isquote(info.outside_quote);
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
		if (ft_isspace(raw[i]) && !info.outside_quote && !info.escaped && !info.inside_quote)
		{
			if (i > 0 && !ft_isspace(raw[i - 1]) && (i == 1 || (i > 1 && raw[i - 2] != '\\')))
			{
				res[info.res_idx++] = my_substr(raw, info.start + chr_isquote(raw[info.start]), i - 1 - (i > 1 && chr_isquote(raw[i - 2])));
				if (!res[info.res_idx - 1])
					return (str_freemtx(res), free(raw), NULL);
			}
			info.start = i + 1;
		}
		else if (chr_isquote(raw[i]) && !info.escaped && !info.outside_quote)
		{
			if (!info.inside_quote)
			{
				info.outside_quote = raw[i];
				info.inside_quote = true;
			}
			else if (raw[i] == info.outside_quote)
			{
				info.inside_quote = false;
				info.outside_quote = 0;
			}
		}
		else if (raw[i] == '\\' && !info.escaped && chr_isquote(info.outside_quote) && chr_isquote(raw[i + 1]))
		{
			info.escaped = true;
			i++;
		}
		else
			info.escaped = raw[i] == '\\' && !info.escaped && chr_isquote(info.outside_quote);
	}
	return (checklast(info, raw, res, i));
}
