/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:01 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/09 02:43:21 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2, int ret)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? s1 : s2);
	if (!(str = ft_strnew(ft_strlen(s1) + ret)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		split_tmp(t_info *f, char **line)
{
	char		*tmp;

	*line = ft_strsub(f->s, 0, f->i);
	tmp = f->s;
	f->s = ft_strdup(&f->s[f->i + 1]);
	free(tmp);
	return (1);
}

int		split_tmp2(t_info *f, char **line)
{
	char		*tmp;

	*line = ft_strdup("");
	tmp = f->s;
	f->s = ft_strdup(f->s + 1);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_info	f;
	char			buff[BUFF_SIZE + 1];

	if (fd == -1)
		return (-1);
	if (!f.s)
		f.s = ft_strdup("");
	if (f.s[0] == '\n')
		return (split_tmp2(&f, line));
	else if (!(f.i = ft_strchr_len(f.s, '\n')))
	{
		while ((f.ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[f.ret] = '\0';
			f.s = ft_strjoin2(f.s, buff, f.ret);
			if ((f.i = ft_strchr_len(f.s, '\n')))
				return (split_tmp(&f, line));
			else if (f.s[0] == '\n')
				return (split_tmp2(&f, line));
		}
	}
	else
		return (split_tmp(&f, line));
	return (f.ret);
}
