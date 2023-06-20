/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:34:27 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:45:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order(t_list *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->lstasize - 1)
	{
		if (stacks->lsta[i] > stacks->lsta[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	raddix_sort(t_list *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (!check_order(stacks))
	{
		j = -1;
		while (j++ < stacks->initsize)
		{
			if (((stacks->lsta[0] >> i) & 1) == 1)
				ra(stacks);
			else
				stacks->lstb = pb(stacks);
		}
		while (stacks->lstbsize != 0)
			stacks->lsta = pa(stacks);
		i++;
	}
	return ;
}
