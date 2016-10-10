/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 03:55:25 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:52:35 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(sizeof(s))) || !s || !f)
		return (NULL);
	while (*s)
	{
		*str = f(*(char*)s);
		s++;
		str++;
		i++;
	}
	return (str - i);
}
