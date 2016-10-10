/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:13:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/18 19:24:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *src)
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	while (i < n)
	{
		ft_bzero(dst, 1);
		i++;
		dst++;
	}
	return (dst - n);
}
