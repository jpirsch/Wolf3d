/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:56:11 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/18 15:47:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen((char*)s2) - 1;
	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		while (s1[i] == s2[i])
		{
			if (i == j)
				return ((char*)s1);
			i++;
		}
		i = 0;
		s1++;
	}
	return (NULL);
}
