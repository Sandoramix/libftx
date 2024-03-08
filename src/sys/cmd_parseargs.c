/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parseargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:16:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/08 16:46:31 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdio.h>

int	count_arguments(const char *raw_str)
{
	int			arg_count;
	char		cur_quote;
	int			escaped;
	int			i;

	escaped = 0;
	arg_count = 0;
	cur_quote = '\0';
	i = -1;
	while (raw_str && raw_str[++i])
	{
		if (raw_str[i] == ' ' && cur_quote == '\0' && !escaped && i > 0
			&& raw_str[i - 1] != ' ')
			arg_count++;
		else if ((raw_str[i] == '\'' || raw_str[i] == '"') && !escaped)
			cur_quote = (int [2]){false, raw_str[i]}[cur_quote == raw_str[i]];
		else if (raw_str[i] == '\\' && !escaped)
			escaped = 1;
		else
			escaped = 0;
	}
	if (raw_str && raw_str[0] != '\0')
		arg_count++;
	return (arg_count);
}

char	**cmd_parse(const char *command)
{
	int arg_count = count_arguments(command);
	char **args = ft_calloc(arg_count + 1, sizeof(char *));
	if (!args)
		return (pf_errcode(ERR_MALLOC), NULL);

	int arg_index = 0;
	char cur_quote = '\0';
	int escaped = 0;
	int arg_start = 0;
	int	slen = str_ilen(command);

	for (int i = 0; i < slen; i++)
	{
		if (command[i] == ' ' && cur_quote == '\0' && !escaped)
		{
			if (i > 0 && command[i - 1] != ' ')
			{
				bool excl = 0;
				args[arg_index] = str_substr(command, arg_start + excl, i - excl);
				if (!args[arg_index])
					return (pf_errcode(ERR_MALLOC), str_freemtx(args), NULL);
				ft_printf("[%d][%s]\texcl[%s]\n", arg_index, args[arg_index], ft_boolstr(excl));
				//args[arg_index] = ft_calloc(i - arg_start + 1, sizeof(char));
				//if (!args[arg_index])
				//	return (pf_errcode(ERR_MALLOC), str_freemtx(args), NULL);
				//ft_memcpy(args[arg_index], command + arg_start + excl, i - arg_start - excl);
				arg_index++;
			}
			arg_start = i + 1;
		}
		else if ((command[i] == '\'' || command[i] == '"') && !escaped)
			cur_quote = (int [2]){0, command[i]}[cur_quote == command[i]];
		else if (command[i] == '\\' && !escaped)
			escaped = 1;
		else
			escaped = 0;
	}
	if (command[arg_start] != '\0')
	{
		args[arg_index] = str_dup(command + arg_start);
		if (!args[arg_index])
			return (pf_errcode(ERR_MALLOC), str_freemtx(args), NULL);
		arg_index++;
	}
	return (args);
}
