/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:55:06 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/27 10:55:31 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line		*init_list(const int fd)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->line = ft_strnew(0);
	new->next = NULL;
	return (new);
}

void		add_element(t_line *list, t_line *new)
{
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = new;
			new->next = NULL;
		}
		list = list->next;
	}
}

char		*init_line(t_line *list, char **line)
{
	char	*tmp;
	char	*txt;
	int		i;

	tmp = NULL;
	i = 0;
	txt = list->line;
	while (txt[i])
	{
		if (txt[i] == EOL)
		{
			*line = ft_strsub(txt, 0, i);
			tmp = txt;
			txt = ft_strdup(txt + (i + 1));
			free(tmp);
			return (txt);
		}
		i++;
	}
	*line = ft_strdup(txt);
	ft_strclr(txt);
	ft_strclr(list->line);
	return (txt);
}

int			read_file(int fd, t_line *list)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	ret = -42;
	while (!ft_strchr(list->line, EOL))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = 0;
			tmp = list->line;
			if (!(list->line = ft_strjoin(list->line, buf)))
				return (-1);
			free(tmp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static t_line		*file;
	int					ret;
	t_line				*tmp;

	if (!file)
		file = init_list(fd);
	tmp = file;
	if (fd < 0 || !line)
		return (-1);
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		if (tmp->next == NULL)
			add_element(tmp, init_list(fd));
		tmp = tmp->next;
	}
	if ((ret = read_file(fd, tmp)) == -1)
		return (-1);
	tmp->line = init_line(tmp, line);
	if (!ft_strlen(tmp->line) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
