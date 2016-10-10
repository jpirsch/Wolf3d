/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 04:49:55 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/10 05:53:35 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 1;
	if (!s1 || !s2)
		return (0);
	j = ft_strlen((char*)s1) - 1;
	if (ft_strlen((char*)s2) - 1 != j)
		return (0);
	while (*s1 == *s2 && i <= n)
	{
		if (i == j || i == n)
			return (1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
