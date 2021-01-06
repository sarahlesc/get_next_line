/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:18:18 by slescure          #+#    #+#             */
/*   Updated: 2021/01/06 15:04:46 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ret(char **save, char **line, char **tmp, int r)
{
	*line = get_line(*save);
	*tmp = *save;
	*save = get_rest(*save);
	free(*tmp);
	if (r < 0)
		return (-1);
	if (r > 0)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save = NULL;
	char			*tmp;
	int				r;

	r = 1;
	if (!save)
	{
		if (!(save = malloc(sizeof(char) * 1)))
			return (-1);
		save[0] = '\0';
	}
	if (fd < 0 || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((ft_strchr(save, '\n') == NULL)
		&& ((r = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[r] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (ret(&save, line, &tmp, r));
}
