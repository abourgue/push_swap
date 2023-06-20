/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:14 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:39:46 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_list *stacks)
{
	int	temp;
	int	i;

	ft_putstr("sb\n");
	if (stacks->lstbsize <= 1)
		return ;
	i = 0;
	temp = stacks->lstb[i];
	stacks->lstb[i] = stacks->lstb[i + 1];
	stacks->lstb[i + 1] = temp;
	return ;
}

int	*pb(t_list *stacks)
{
	int	*newb;
	int	i;

	newb = malloc((stacks->lstbsize + 1) * sizeof(int));
	if (!newb || stacks->lstasize <= 0)
		return (stacks->lstb);
	ft_putstr("pb\n");
	stacks->lstbsize++;
	i = 0;
	newb[i] = stacks->lsta[0];
	i++;
	if (stacks->lstbsize > 0)
	{
		while (i < stacks->lstbsize)
		{
			newb[i] = stacks->lstb[i - 1];
			i++;
		}
	}
	free(stacks->lstb);
	stacks->lsta = supress_a(stacks);
	stacks->lstasize--;
	return (newb);
}

void	rb(t_list *stacks)
{
	int	i;
	int	temp;

	ft_putstr("rb\n");
	if (stacks->lstbsize <= 1)
		return ;
	i = 0;
	temp = stacks->lstb[0];
	while (i < stacks->lstbsize - 1)
	{
		stacks->lstb[i] = stacks->lstb[i + 1];
		i++;
	}
	stacks->lstb[stacks->lstbsize - 1] = temp;
	return ;
}

void	rrb(t_list *stacks)
{
	int	i;
	int	temp;

	ft_putstr("rrb\n");
	if (stacks->lstbsize <= 1)
		return ;
	i = stacks->lstbsize - 1;
	temp = stacks->lstb[i];
	while (i > 0)
	{
		stacks->lstb[i] = stacks->lstb[i - 1];
		i--;
	}
	stacks->lstb[0] = temp;
	return ;
}
