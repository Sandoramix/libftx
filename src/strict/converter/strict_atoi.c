/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:50:33 by odudniak          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/03 19:06:24 by odudniak         ###   ########.fr       */
=======
/*   Updated: 2024/01/03 19:03:09 by odudniak         ###   ########.fr       */
>>>>>>> c1bbb65defe07a50e33dfcd80d950697b1e568df
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*x_freetwo(void *m1, void *m2)
{
	if (m1)
		free(m1);
	if (m2)
		free(m2);
	return (NULL);
}

int	*strict_atoi(const char *s)
{
	int		*r;
	char	*trim;
	int		sign;
	int		prev;
	int		i;

	trim = ft_strtrim(s, " \t\n\v\f\r");
	if (!ft_istrlen(trim) || !ft_strevery(trim + (int [2]){0, 1}
		[ft_issign(trim[0])], &ft_isdigit))
		return (ft_free(trim));
	r = malloc(sizeof(int));
	if (!r)
		return (ft_free(trim));
	sign = (int [2]){1, -1}[trim[0] == '-'];
	*r = 0;
	i = (int [2]){-1, 0}[ft_issign(trim[0])];
	while (trim[++i])
	{
		prev = *r;
		*r = *r * 10 + (int [2]){0 - (trim[i] - '0'), trim[i] - '0'}[sign == 1];
		if (prev != *r / 10)
			return (x_freetwo(r, trim));
	}
	free(trim);
	return (r);
}
