/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:42:15 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/21 16:44:59 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			find_endl(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			str[len] = '\0';
			return (len);
		}
		len++;
	}
	return (-42);
}

char				*my_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (res);
}

static int			write_in_line(char **buff, char **line, char **temp)
{
	int				len;
	char			*rofl;

	if (*buff)
		*buff = my_strjoin(*buff, *temp);
	else
	{
		*buff = ft_strdup(*temp);
		ft_memdel((void**)temp);
	}
	if ((len = find_endl(*buff)) != -42)
	{
		*line = ft_strdup(*buff);
		rofl = *buff;
		*buff = ft_strdup(*buff + len + 1);
		ft_memdel((void**)&rofl);
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char		*buff[4200];
	int				ret;
	int				n_found;
	char			*temp;

	temp = ft_strnew(BUFF_SIZE);
	if (BUFF_SIZE < 0 || fd < 0 || !line || (ret = read(fd, temp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if ((n_found = write_in_line(&buff[fd], line, &temp)) == 1)
			return (1);
		temp = ft_strnew(BUFF_SIZE);
	}
	if ((n_found = write_in_line(&buff[fd], line, &temp)) == 1)
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_memdel((void**)&buff[fd]);
		return (1);
	}
	ft_memdel((void**)&buff[fd]);
	return (0);
}
