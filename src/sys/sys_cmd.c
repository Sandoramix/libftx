/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:38:09 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/02 16:09:33 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// TODO decision: return `NULL` or copy of `cmd`
char	*sys_findcmdpath(char **paths, char *cmd)
{
	int			i;
	char		*res;

	if (!paths || !cmd)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		if (!str_endswith(paths[i], "/"))
			res = str_join(paths[i], "/");
		else
			res = str_dup(paths[i]);
		if (!res)
			return (NULL);
		res = str_freejoin(res, cmd);
		if (!res)
			return (NULL);
		if (file_hasperm(res, X_OK))
			return (res);
		free(res);
	}
	return (cmd);
}

t_list	*sys_loadcmds(char **cmds, char **paths)
{
	t_list		*res;
	char		**spl;
	char		*cmdname;
	char		*path;
	int			i;

	i = -1;
	res = NULL;
	while (cmds && paths && cmds[++i])
	{
		spl = str_split_first(cmds[i], ' ');
		if (!spl)
			return (NULL);
		cmdname = spl[0];
		spl[0] = NULL;
		if (lst_findbykey(res, cmdname,
				(bool (*)(void *, void *))str_equals) && ++i)
			continue ;
		path = sys_findcmdpath(paths, cmdname);
		if (!lst_addnew_tail(&res, path, cmdname))
			return (str_freemtx(spl), NULL);
		str_freemtx(spl);
		i++;
	}
	return (res);
}
