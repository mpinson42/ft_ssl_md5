/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:57:51 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/27 11:40:06 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	check_static(char *str)
{
	int	index;

	index = -1;
	if (!str)
		return (0);
	while (str[++index] != '\0')
	{
		if (str[index] == '\n')
			return (index + 1);
	}
	return (0);
}

static int		read_fd(int fd, char *buf)
{
	int		ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) != -1)
		buf[ret] = '\0';
	return (ret);
}

static char		*free_join(char *s1, char *s2, int lib)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1 && (lib == 3 || lib == 2))
		ft_memdel((void **)&s1);
	if (s2 && (lib == 3 || lib == 1))
		ft_memdel((void **)&s2);
	return (tmp);
}

static t_fd		*get_fd(t_fd *lst_fd, int fd)
{
	t_fd	*l_tmp;

	l_tmp = lst_fd;
	if (l_tmp)
	{
		while (l_tmp->next)
		{
			if (l_tmp->fd == fd)
				return (l_tmp);
			l_tmp = l_tmp->next;
		}
		if (l_tmp->fd == fd)
			return (l_tmp);
		if (!(l_tmp->next = (t_fd *)malloc(sizeof(t_fd))))
			return (NULL);
		l_tmp = l_tmp->next;
	}
	else if (!(l_tmp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	l_tmp->fd = fd;
	l_tmp->lne = ft_strdup("");
	l_tmp->next = NULL;
	l_tmp->srt = (!lst_fd) ? l_tmp : lst_fd;
	return (l_tmp);
}

int				get_next_line(int const fd, char **line)
{
	static t_fd		*cur_fd = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				len;
	int				ret;

	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	cur_fd = get_fd(cur_fd, fd);
	while (fd >= 0 && ((len = check_static(cur_fd->lne)) ||
				(ret = read_fd(fd, buf)) > 0) && len <= 0)
		cur_fd->lne = free_join(cur_fd->lne, buf, 2);
	if (ret == -1)
		return (-1);
	if (len > 0)
		cur_fd->lne[len - 1] = '\0';
	*line = ft_strdup(cur_fd->lne);
	str = cur_fd->lne;
	cur_fd->lne = ((len > 0) ? ft_strdup(cur_fd->lne + len) : ft_strdup(""));
	free(str);
	cur_fd = cur_fd->srt;
	return ((len || **line) ? 1 : 0);
}
