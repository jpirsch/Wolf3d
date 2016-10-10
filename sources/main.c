/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/01 19:03:36 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "wolf.h"

int		**mapi(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	map = malloc(sizeof(int *) * 21);
	while (i < 20)
	{
		map[i] = malloc(sizeof(int) * 11);
		j = 0;
		while (j < 9 && i != 0 && i != 19)
		{
			map[i][j] = 0;
			j++;
		}
		while (j < 10 && (i == 0 || i == 19))
		{
			map[i][j] = 1;
			j++;
		}
		map[i][0] = 20;
		map[i][9] = 1;
		i++;
	}
	return (map);
}

int		**mapo(int **map)
{
	if (!map)
		return (NULL);
	map[2][5] = 1;
	map[3][5] = 1;
	map[4][5] = 1;
	map[6][8] = 1;
	map[6][7] = 1;
	map[12][2] = 1;
	map[13][2] = 1;
	map[14][5] = 1;
	map[16][5] = 1;
	map[16][4] = 1;
	return (map);
}

int		main(void)
{
	int	**map;

	if ((map = mapi()) != NULL)
		if ((map = mapo(map)) != NULL)
			if (!(sdl_env(map)))
				return (-1);
	return (0);
}
