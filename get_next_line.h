/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:23:17 by slescure          #+#    #+#             */
/*   Updated: 2020/11/16 16:18:43 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

int 		get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *str, int c);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *src);
char		*get_rest(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*get_line(char *str);
#endif
