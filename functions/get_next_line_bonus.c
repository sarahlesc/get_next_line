/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:34:12 by slescure          #+#    #+#             */
/*   Updated: 2021/01/11 14:36:22 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	initialisation(int fd, char **save, char **line, char **buf)
{
	if (!*save)
	{
		if (!(*save = malloc(sizeof(char) * 1)))
			return (-1);
		*save[0] = '\0';
	}
	if (fd < 0 || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	return (1);
}

int	ret(char **save, char **line, char **tmp, int r)
{
	*line = get_line(*save);
	*tmp = *save;
	*save = get_rest(*tmp);
	free(*tmp);
	if (r < 0)
		return (-1);
	if (r > 0)
		return (1);
	free(*save);
	*save = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save[FD_SIZE];
	char			*tmp;
	int				r;

	r = 1;
	if ((r = initialisation(fd, &save[fd], line, &buf)) == -1)
		return (-1);
	if ((ft_strchr(save[fd], '\n') == NULL))
	{
		while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[r] = '\0';
			tmp = save[fd];
			save[fd] = ft_strjoin(tmp, buf);
			free(tmp);
			if (!(ft_strchr(buf, '\n') == NULL))
				break ;
		}
	}
	free(buf);
	return (ret(&save[fd], line, &tmp, r));
}
