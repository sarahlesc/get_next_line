/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:29:54 by slescure          #+#    #+#             */
/*   Updated: 2021/01/08 17:40:28 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#   define FD_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		initialisation(int fd, char **save, char **line, char **buf);
int		ret(char **save, char **line, char **tmp, int r);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*get_rest(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *str);

#endif
