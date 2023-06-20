/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:04:31 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:44:27 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_three(t_list *stacks)
{
	if (stacks->lsta[0] > stacks->lsta[1])
		sa(stacks);
	if (stacks->lstasize > 2)
	{
		if (stacks->lsta[0] > stacks->lsta[2])
			rra(stacks);
		if (stacks->lsta[1] > stacks->lsta[2])
		{
			rra(stacks);
			sa(stacks);
		}
	}
	return ;
}

void	pa_sort(t_list *stacks)
{
	int	i;

	while (stacks->lstbsize > 0)
	{
		i = 0;
		if (stacks->lstb[0] < stacks->lsta[0])
			stacks->lsta = pa(stacks);
		else
		{
			while (stacks->lstb[0] > stacks->lsta[0] && i < stacks->lstasize)
			{
				ra(stacks);
				i++;
			}
			stacks->lsta = pa(stacks);
			while (i != 0)
			{
				rra(stacks);
				i--;
			}
		}
	}
}

void	algo_five(t_list *stacks)
{
	if (!check_order(stacks))
	{
		while (stacks->lstbsize != 2)
		{
			if (stacks->lsta[0] == 1 || stacks->lsta[0] == 2)
				stacks->lstb = pb(stacks);
			else
				ra(stacks);
		}
		if (stacks->lstb[0] == 1)
			sb(stacks);
		algo_three(stacks);
		stacks->lsta = pa(stacks);
		stacks->lsta = pa(stacks);
	}
	return ;
}
