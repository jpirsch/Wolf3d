/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 07:56:07 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:54:26 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_filltab(const char *s, char c, size_t n, char **strtab)
{
	size_t size;
	size_t i;

	size = 0;
	i = 0;
	while (i <= n)
	{
		if ((size = ft_strchr_len(s, c)) == 0)
			size = ft_strlen((char*)s);
		strtab[i] = ft_strsub(s, 0, size);
		s = s + size + 1;
		i++;
	}
	free(strtab);
	return (strtab);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**strtab;
	size_t	n;

	if (!s || !c)
		return (NULL);
	n = ft_countwords(s, c);
	if (!(strtab = ft_tabmalloc(n + 1, ft_strlen((char*)s))))
		return (NULL);
	if (!n)
		strtab[0] = NULL;
	else
	{
		s = ft_strtrim_char(s, c);
		if (n == 1)
			strtab[0] = ft_strdup((char*)s);
		else
			strtab = ft_filltab(s, c, n, strtab);
	}
	return (strtab);
}
