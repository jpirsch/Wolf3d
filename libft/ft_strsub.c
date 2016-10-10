/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 06:05:31 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/19 01:20:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !len)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	s += start;
	while (len--)
	{
		str[i] = s[i];
		if (str[i] == '\0')
			return (str);
		i++;
	}
	str[i] = '\0';
	return (str);
}
