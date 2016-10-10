/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:29:57 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:35:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcleaner(const char *s, size_t startblanks, size_t endblanks)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	str = ft_strdup((char*)s);
	if (!startblanks && !endblanks)
		return (str);
	else
		size = ft_strlen((char *)s) - startblanks - endblanks + 1;
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s && i < size - 1)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_countblanks(const char *s, size_t loops, size_t slen)
{
	size_t	startblanks;
	size_t	endblanks;

	startblanks = 0;
	endblanks = 0;
	while (*s)
	{
		while (loops == 0 && (*s == ' ' || *s == '\n' || *s == '\t'))
		{
			s++;
			startblanks++;
		}
		if (*s != ' ' && *s != '\n' && *s != '\t')
		{
			loops = 1;
			endblanks = 0;
			s++;
		}
		while (*s == ' ' || *s == '\n' || *s == '\t')
		{
			endblanks++;
			s++;
		}
	}
	return (ft_strcleaner(s - slen, startblanks, endblanks));
}

char		*ft_strtrim(const char *s)
{
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = ft_countblanks(s, 0, ft_strlen((char*)s))))
		return (NULL);
	return (str);
}
