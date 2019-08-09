/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:02:27 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 11:02:54 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ssort_b(t_stack *a, t_stack *b, int i)
{
	int		iter;

	iter = -1;
	if (i < (a->last + 1) / 2)
	{
		i++;
		while (++iter != i)
		{
			ft_revrot(a);
			ft_putendl("rra");
		}
	}
	else
	{
		i = a->last - i;
		while (++iter != i)
		{
			ft_rot(a);
			ft_putendl("ra");
		}
	}
	ft_push(a, b);
	ft_putendl("pb");
}

void	ft_ssort(t_stack a, t_stack b)
{
	int		min;
	int		imin;
	int		i;

	while (a.last != -1)
	{
		i = a.last + 1;
		min = 2147483647;
		while (--i != -1)
			if (min > a.arr[i])
			{
				min = a.arr[i];
				imin = i;
			}
		ft_ssort_b(&a, &b, imin);
	}
	ft_fillstack(&b, &a, "pa");
}