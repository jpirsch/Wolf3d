/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:46:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:35:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	s = ft_strnew(11);
	ft_bzero(s, 11);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n == 0)
		return (ft_strcpy(s, "0"));
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (reverse(s));
}
