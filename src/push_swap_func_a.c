/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:09:33 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:40:04 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list *stacks)
{
	int	temp;
	int	i;

	ft_putstr("sa\n");
	if (stacks->lstasize <= 1)
		return ;
	i = 0;
	temp = stacks->lsta[i];
	stacks->lsta[i] = stacks->lsta[i + 1];
	stacks->lsta[i + 1] = temp;
	return ;
}

int	*pa(t_list *stacks)
{
	int	*newa;
	int	i;

	ft_putstr("pa\n");
	newa = malloc((stacks->lstasize + 1) * sizeof(int));
	if (!newa || stacks->lstbsize <= 0)
		return (stacks->lsta);
	stacks->lstasize++;
	i = 0;
	newa[i] = stacks->lstb[0];
	i++;
	if (stacks->lstasize > 0)
	{
		while (i < stacks->lstasize)
		{
			newa[i] = stacks->lsta[i - 1];
			i++;
		}
	}
	free(stacks->lsta);
	stacks->lstb = supress_b(stacks);
	stacks->lstbsize--;
	return (newa);
}

void	ra(t_list *stacks)
{
	int	i;
	int	temp;

	ft_putstr("ra\n");
	if (stacks->lstasize <= 1)
		return ;
	i = 0;
	temp = stacks->lsta[0];
	while (i < stacks->lstasize - 1)
	{
		stacks->lsta[i] = stacks->lsta[i + 1];
		i++;
	}
	stacks->lsta[stacks->lstasize - 1] = temp;
	return ;
}

void	rra(t_list *stacks)
{
	int	i;
	int	temp;

	ft_putstr("rra\n");
	if (stacks->lstasize <= 1)
		return ;
	i = stacks->lstasize - 1;
	temp = stacks->lsta[i];
	while (i > 0)
	{
		stacks->lsta[i] = stacks->lsta[i - 1];
		i--;
	}
	stacks->lsta[0] = temp;
	return ;
}
