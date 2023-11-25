/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:37:24 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/22 14:42:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnl.h"

int	main(void)
{
	int fd = open("empty", O_RDONLY);
	char *str = get_next_line(fd);
	ft_printf("%s", str);
	while(str){
		free(str);
		str = get_next_line(fd);
		printf("%s", str);
	}
	free(str);
	return (0);
}
