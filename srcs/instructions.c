/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:08:22 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/05 15:40:01 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stck)
{
	int elem;

	if (stck->last >= 1)
	{
		elem = stck->arr[stck->last];
		stck->arr[stck->last] = stck->arr[stck->last - 1];
		stck->arr[stck->last - 1] = elem;
	}
}

void	ft_push(t_stack *src, t_stack *dst)
{
	if (src->last != -1)
	{
		dst->last++;
		dst->arr[dst->last] = src->arr[src->last];
		src->arr[src->last] = 0;
		src->last--;
	}
}

void	ft_rot(t_stack *stck)
{
	int	elem;
	int	i;

	if (stck->last != -1)
	{
		i = stck->last;
		elem = stck->arr[stck->last];
		while (i > 0)
		{
			stck->arr[i] = stck->arr[i - 1];
			i--;
		}
		stck->arr[0] = elem;
	}
}

void	ft_revrot(t_stack *stck)
{
	int	elem;
	int	i;

	if (stck->last != -1)
	{
		i = 0;
		elem = stck->arr[0];
		while (i < stck->last)
		{
			stck->arr[i] = stck->arr[i + 1];
			i++;
		}
		stck->arr[stck->last] = elem;
	}
}
