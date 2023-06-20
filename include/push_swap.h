/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:53:59 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:41:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_list
{
	int	initsize;
	int	*lsta;
	int	lstasize;
	int	*lstb;
	int	lstbsize;
	int	count;
}	t_list;

int		*supress_a(t_list *stacks);
int		*supress_b(t_list *stacks);
int		*pb(t_list *stacks);
int		*pa(t_list *stacks);
void	sa(t_list *stacks);
void	ra(t_list *stacks);
void	rra(t_list *stacks);
void	sb(t_list *stacks);
void	rb(t_list *stacks);
void	rrb(t_list *stacks);
void	algo_three(t_list *stacks);
void	algo_five(t_list *stacks);
void	pa_sort(t_list *stacks);
void	neg_to_pos(t_list *stacks);
int		check_val(int size, char **value);
void	raddix_sort(t_list *stacks);
int		check_order(t_list *stacks);
#endif