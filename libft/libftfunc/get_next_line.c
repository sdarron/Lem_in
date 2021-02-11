/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2019/10/17 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*movestr(char *s)
{
	char	*a;
	int		k;
	int		i;

	a = ft_strchr(s, '\n');
	if (!a)
	{
		ft_strclr(s);
		return (s);
	}
	k = a - s + 1;
	i = 0;
	while (s[i + k])
	{
		s[i] = s[i + k];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int		appendstr(char **m, const int fd, char **s)
{
	char	*a;

	a = ft_strchr(m[fd], '\n');
	*s = ft_strsub(m[fd], 0, a - m[fd]);
	m[fd] = movestr(m[fd]);
	return (1);
}

int		finish_part(char **m, const int fd, char **line, int r)
{
	if (r == 0)
	{
		*line = ft_strdup(m[fd]);
		ft_strclr(m[fd]);
		if (**line == '\0')
		{
			free(*line);
			*line = NULL;
			free(m[fd]);
			m[fd] = NULL;
			return (0);
		}
	}
	if (r < 0)
		return (-1);
	return (1);
}

char	*join(char **m, char *buf, const int fd)
{
	char	*s;

	s = ft_strjoin(m[fd], buf);
	free(m[fd]);
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	static char	*m[OPEN_MAX];
	int			r;
	char		buf[BUFF_SIZE + 1];

	if ((fd < 0) || !line || (fd > OPEN_MAX))
		return (-1);
	*line = NULL;
	if (m[fd] && ft_strchr(m[fd], '\n'))
		return (appendstr(m, fd, line));
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (m[fd])
			m[fd] = join(m, buf, fd);
		else
			m[fd] = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			return (appendstr(m, fd, line));
	}
	if ((r == 0) && !m[fd])
		return (0);
	return (finish_part(m, fd, line, r));
}
