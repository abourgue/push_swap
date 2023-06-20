/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:11:30 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:32:32 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init(int size, t_list *stacks, char	**value)
{
	int	i;

	i = 0;
	stacks->initsize = size - 1;
	stacks->lstbsize = 0;
	stacks->count = 1;
	stacks->lstb = malloc(stacks->lstbsize);
	stacks->lsta = malloc(size * sizeof(int));
	if (!stacks->lsta)
		return (0);
	value++;
	while (i < size)
	{
		stacks->lsta[i] = ft_atoi(value[i]);
		stacks->lstasize++;
		i++;
	}
	return (1);
}

int	is_duplicate(int size, int *temp, char **value)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i <= size)
	{
		while (x <= size - 1)
		{
			if (temp[x] == ft_atoi(value[i]) && x != i - 1)
				return (0);
			x++;
		}
		x = 0;
		i++;
	}
	return (1);
}

int	check_val(int size, char **value)
{
	int	i;
	int	*temp;

	temp = malloc(size * sizeof(int));
	i = 1;
	while (i < size)
	{
		temp[i - 1] = ft_atoi(value[i]);
		i++;
	}
	if (is_duplicate(size, temp, value) != 1)
		return (0);
	free(temp);
	return (1);
}

void	push_swap(int size, char **value)
{
	static t_list	list = {.initsize = -1};

	size--;
	if (init(size, &list, value) != 1)
		return (ft_putstr("Error_1\n"));
	if (check_val(size, value) != 1)
		return (ft_putstr("Error_2\n"));
	neg_to_pos(&list);
	if (list.lstasize <= 3 && list.lstasize > 1 && !check_order(&list))
		algo_three(&list);
	if (list.lstasize > 3 && list.lstasize <= 5 && check_order(&list) != 1)
		algo_five(&list);
	if (list.lstasize > 5)
		raddix_sort(&list);
	free(list.lsta);
	free(list.lstb);
	return ;
}

int	main(int argc, char	**argv)
{
	if (argc <= 1)
		return (0);
	push_swap(argc, argv);
	return (0);
}
