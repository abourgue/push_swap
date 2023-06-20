/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:24 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:42:13 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*supress_a(t_list *stacks)
{
	int	*newtab;
	int	x;

	x = 0;
	if (stacks->lstasize == 0)
		return (stacks->lsta);
	newtab = malloc((stacks->lstasize) * sizeof(int));
	if (!newtab)
		return (stacks->lsta);
	while (x + 1 < stacks->lstasize)
	{
		newtab[x] = stacks->lsta[x + 1];
		x++;
	}
	free(stacks->lsta);
	return (newtab);
}

int	*supress_b(t_list *stacks)
{
	int	*newtab;
	int	x;

	if (stacks->lstbsize == 0 || stacks->lstbsize == 1)
		return (stacks->lstb);
	else
		newtab = malloc((stacks->lstbsize) * sizeof(int));
	if (!newtab)
		return (stacks->lstb);
	x = 0;
	while (x + 1 < stacks->lstbsize)
	{
		newtab[x] = stacks->lstb[x + 1];
		x++;
	}
	free(stacks->lstb);
	return (newtab);
}
