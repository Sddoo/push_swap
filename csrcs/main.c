/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:57:48 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 22:54:50 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkoper2(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "pa"))
		ft_push(b, a);
	else if (!ft_strcmp(str, "pb"))
		ft_push(a, b);
	else if (!ft_strcmp(str, "ra"))
		ft_rot(a);
	else if (!ft_strcmp(str, "rb"))
		ft_rot(b);
	else if (!ft_strcmp(str, "rr"))
	{
		ft_rot(a);
		ft_rot(b);
	}
	else if (!ft_strcmp(str, "rra"))
		ft_revrot(a);
	else if (!ft_strcmp(str, "rrb"))
		ft_revrot(b);
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_revrot(a);
		ft_revrot(b);
	}
	else
		ft_error();
}

int		ft_checkoper(t_stack *a, t_stack *b)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (!ft_strcmp(str, "sa"))
			ft_swap(a);
		else if (!ft_strcmp(str, "sb"))
			ft_swap(b);
		else if (!ft_strcmp(str, "ss"))
		{
			ft_swap(a);
			ft_swap(b);
		}
		else
			ft_checkoper2(a, b, str);
		free(str);
	}
	if (ft_checkorder(*a, *b))
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_stackinit(&a, &b, &argc, &argv);
	ft_initstacka(&a, argc, argv);
	if (!ft_checkoper(&a, &b))
	{
		free(a.arr);
		free(b.arr);
		ft_putstr("KO\n");
		return (0);
	}
	free(a.arr);
	free(b.arr);
	ft_putstr("OK\n");
	return (0);
}
