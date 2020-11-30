/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:18:18 by slescure          #+#    #+#             */
/*   Updated: 2020/11/30 21:54:37 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save = "";
	int				r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while ((ft_strchr(save, '\n') == NULL)
		&& ((r = read(fd, buf, BUFFER_SIZE)) > 0))
		{
			buf[r] = '\0';
			save = ft_strjoin(save, buf);
		}
	*line = get_line(save);
	save = get_rest(save);
	if (r < 0)
		return (-1);
	if (r == 0)
		return (0);
	if (r > 0)
		return (1);
	return (0);
}
