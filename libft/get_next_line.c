/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:00:00 by dtomchys          #+#    #+#             */
/*   Updated: 2017/12/12 21:00:38 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_find_line(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static t_list		*ft_file_descriptor(t_list **alst, int fd)
{
	t_list *files;

	files = *alst;
	while (files)
	{
		if (fd == (int)files->content_size)
			return (files);
		files = files->next;
	}
	if (!(files = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	files->content_size = fd;
	files->content = ft_strdup("\0");
	ft_lstadd(alst, files);
	return (files);
}

static int			ft_make_line(int i, t_list **current, char **s)
{
	int j;

	if (i == -1)
		return (-1);
	if (i == 0 && !(ft_strlen((*current)->content)))
		return (0);
	j = ft_find_line((*current)->content);
	if (j != (-1))
	{
		*s = ft_strsub((*current)->content, 0, j);
		(*current)->content = ft_strcpy((*current)->content,\
										(*current)->content + (j + 1));
	}
	else
	{
		*s = ft_strdup((*current)->content);
		ft_memset((*current)->content, '\0', ft_strlen((*current)->content));
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*temp;
	char			buf[BUFF_SIZE + 1];
	int				bytes;
	char			*t;

	if (fd < 0 || !line)
		return (-1);
	if (!(temp = ft_file_descriptor(&files, fd)))
		return (-1);
	while ((bytes = read(temp->content_size, buf, BUFF_SIZE)) > 0)
	{
		t = ft_strdup(temp->content);
		buf[bytes] = '\0';
		free(temp->content);
		temp->content = ft_strjoin(t, buf);
		free(t);
		if (ft_find_line(buf) != (-1))
			break ;
	}
	return (ft_make_line(bytes, &temp, line));
}
