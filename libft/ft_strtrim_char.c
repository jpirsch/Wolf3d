/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:29:57 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:36:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcleaner(const char *s, size_t startblanks, size_t endblanks)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	if (!startblanks && !endblanks)
		return ((char*)s);
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

static char	*ft_countblanks(const char *s, size_t loops, size_t slen, char c)
{
	size_t	startblanks;
	size_t	endblanks;

	startblanks = 0;
	endblanks = 0;
	while (*s)
	{
		while (loops == 0 && *s == c)
		{
			s++;
			startblanks++;
		}
		if (*s != c)
		{
			loops = 1;
			endblanks = 0;
			s++;
		}
		while (*s == c)
		{
			endblanks++;
			s++;
		}
	}
	return (ft_strcleaner(s - slen, startblanks, endblanks));
}

char		*ft_strtrim_char(const char *s, char c)
{
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = ft_countblanks(s, 0, ft_strlen((char*)s), c)))
		return (NULL);
	return (str);
}
