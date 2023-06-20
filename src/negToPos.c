/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negToPos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:34:14 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:31:29 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(int *xp, int *yp)
{
	int	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void	selection_sort(int *sort_cp, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < size)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (sort_cp[j] < sort_cp[min_idx])
				min_idx = j;
			j++;
		}
		swap(&sort_cp[min_idx], &sort_cp[i]);
		i++;
	}
}

void	apply_mask(int *arr, int *mask, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == mask[j])
			{
				arr[i] = j + 1;
				i++;
				j = 0;
				if (i >= size)
					break ;
				continue ;
			}
			j++;
		}
		i++;
	}
	free(mask);
}

int	*copy(int *res, t_list *stacks)
{
	int	i;

	i = 0;
	res = malloc(stacks->lstasize * sizeof(int));
	while (i <= stacks->initsize)
	{
		res[i] = stacks->lsta[i];
		i++;
	}
	return (res);
}

void	neg_to_pos(t_list *stacks)
{
	int	*sort_cp;

	sort_cp = NULL;
	sort_cp = copy(sort_cp, stacks);
	selection_sort(sort_cp, stacks->lstasize);
	apply_mask(stacks->lsta, sort_cp, stacks->lstasize);
}
