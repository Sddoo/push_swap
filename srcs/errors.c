/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:44:27 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 22:57:23 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_showstacks(t_stack stck, t_stack stck1)
{
	while (stck.last >= 0 || stck1.last >= 0)
	{
		if (stck.last != -1)
		{
			printf("%d ", stck.arr[stck.last]);
			stck.last--;
		}
		if (stck1.last != -1)
		{
			printf("%5d", stck1.arr[stck1.last]);
			stck1.last--;
		}
		printf("\n");
	}
	ft_putstr("-\n");
}

int		ft_checkorder(t_stack a, t_stack b)
{
	if (b.last != -1)
		return (0);
	a.last--;
	while (a.last != -1)
	{
		if (a.arr[a.last + 1] > a.arr[a.last])
			return (0);
		a.last--;
	}
	return (1);
}

int		ft_checkarg(char *str)
{
	int		count;

	count = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1])
		count++;
	while (str[count])
	{
		if (!ft_isdigit(str[count] - '\0'))
			return (1);
		count++;
	}
	return (0);
}

int		ft_checkduplicate(t_stack a)
{
	int nmb;

	if (!a.last)
		return (0);
	nmb = a.arr[a.last];
	while (a.last--)
		if (nmb == a.arr[a.last])
			return (1);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
