/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:25:53 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/18 19:51:53 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = ft_strlen((char*)s2) - 1;
	k = 0;
	if (!*s2)
		return ((char*)s1);
	while (*s1 && k < n)
	{
		while (s1[i] == s2[i] && (i + k) < n)
		{
			if (i == j)
				return ((char*)s1);
			i++;
		}
		i = 0;
		k++;
		s1++;
	}
	return (NULL);
}
