/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:43:44 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/10 04:26:14 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabmalloc(size_t nbstr, size_t slen)
{
	char	**stab;
	size_t	i;

	i = 0;
	if (!(stab = malloc(sizeof(char*) * nbstr)))
		return (NULL);
	ft_bzero(stab, nbstr);
	while (i < nbstr)
	{
		if (!(stab[i] = (char*)malloc(sizeof(char*) * slen)))
			return (NULL);
		ft_bzero(stab[i], slen);
		i++;
	}
	return (stab);
}
