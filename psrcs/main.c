/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:40:56 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 21:40:06 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fillstack(t_stack *src, t_stack *dst, char *str)
{
	while (src->last != -1)
	{
		ft_push(src, dst);
		ft_putendl(str);
	}
}

int		ft_getimin(t_stack *stck)
{
	int		min;
	int		imin;
	int		i;

	i = -1;
	min = 2147483647;
	while (i++ < stck->last)
	{
		if (stck->arr[i] < min)
		{
			min = stck->arr[i];
			imin = i;
		}
	}
	stck->arr[imin] = 2147483647;
	return (imin);
}

void	ft_index(t_stack *a)
{
	int imin;
	t_stack b;
	int i;

	b = *a;
	i = 0;
	if (!(b.arr = (int*)malloc(4 * b.size)))
		exit(0);
	while (i <= a->last)
	{
		b.arr[i] = a->arr[i];
		i++;
	}
	i = 0;
	while (i <= a->last)
	{
		imin = ft_getimin(&b);
		a->arr[imin] = i++;
	}
	free(b.arr);
}

// void	ft_send_to_another(t_stack *src, t_stack *dst, int i) // попробвать изменить для а и б
// {
// 	int		count;

// 	count = -1;
// 	if (i < (src->last + 1) / 2)
// 	{
// 		i++;
// 		while (++count != i)
// 		{
// 			ft_revrot(src);
// 			ft_putendl("rra");
// 		}
// 	}
// 	else
// 	{
// 		i = src->last - i;
// 		while (++count != i)
// 		{
// 			ft_rot(src);
// 			ft_putendl("ra");
// 		}
// 	}
// 	ft_push(src, dst);
// 	ft_putendl("pb");
// }

// int		ft_instrcount(t_stack src, t_stack dst, int i)
// {
// 	int		count;

// 	count = -1;
// 	(void)dst;
// 	if (i < (src.last + 1) / 2)
// 		count = i;
// 	else
// 		count = src.last - i + 1;
// 	return (count);
// }

int			ft_find_closest(t_stack dst, int nbr)
{
	int		i;
	int		iclosest;
	int 	closest;

	i = dst.last;
	closest = dst.size - 1;
	while (i != -1)
	{
		if (dst.arr[i] <= closest && dst.arr[i] > nbr)
		{
			closest = dst.arr[i];
			iclosest = i;
		}
		i--;
	}
	return (iclosest);
}

void		ft_push_to_a(t_stack *a, t_stack *b, int i)
{
	int index;
	int count;
	int	j;

	j = 0;
	index = ft_find_closest(*a, b->arr[i]);
	if (index < (a->last + 1) / 2)
	{
		count = index + 1;
		while (j < count)
		{
			ft_revrot(a);
			ft_putendl("rra");
			j++;
		}
	}
	else
	{
		count = a->last - index;
		while (j < count)
		{
			ft_rot(a);
			ft_putendl("ra");
			j++;
		}
	}
	j = 0;
	if (i < (b->last + 1) / 2)
	{
		count = i + 1;
		while (j < count)
		{
			ft_revrot(b);
			ft_putendl("rrb");
			j++;
		}
	}
	else
	{
		count = b->last - i;
		while (j < count)
		{
			ft_rot(b);
			ft_putendl("rb");
			j++;
		}
	}
	ft_push(b, a);
	ft_putendl("pa");
}

int			ft_instrcount(t_stack a, t_stack b, int i)
{
	int		count;
	int		index;

	count = 0;
	index = ft_find_closest(a, b.arr[i]);
	if (index < (a.last + 1) / 2)
		count += index + 1;
	else
		count += a.last - index;
	if (i < (b.last + 1) / 2)
		count += i + 1;
	else
		count += b.last - i;
	return (count);
}

void	ft_tsort_to_a(t_stack *a, t_stack *b)
{
	int min;
	int imin;
	int	count;
	int i;

	while (b->last != -1)
	{
		i = b->last;
		min = 2147483647;
		while (i != -1)
		{
			count = ft_instrcount(*a, *b, i);
			if (count < min)
			{
				min = count;
				imin = i;
			}
			i--;
		}
		ft_push_to_a(a, b, imin);
		ft_showstacks(*a, *b);
	}
}

void	ft_tsort_to_b(t_stack *a, t_stack *b)
{
	while (a->last != 1)
	{
		if (a->arr[a->last] == a->size - 1)
		{
			ft_rot(a);
			ft_putendl("ra");
		}
		ft_push(a, b);
		ft_putendl("pb");
	}
}

void	ft_tsort(t_stack a, t_stack b)
{
	int i;
	int j;
	int count;

	ft_tsort_to_b(&a, &b);
	ft_tsort_to_a(&a, &b);
	i = 0;
	j = 0;
	while (a.arr[i] != 0)
		i++;
	if (i < (a.last + 1) / 2)
	{
		count = i + 1;
		while (j < count)
		{
			ft_revrot(&a);
			ft_putendl("rra");
			j++;
		}
	}
	else
	{
		count = a.last - i;
		while (j < count)
		{
			ft_rot(&a);
			ft_putendl("ra");
			j++;
		}
	}
}

int     main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	ft_stackinit(&a, &b, &argc, &argv);
	ft_initstacka(&a, argc, argv);
	if (ft_checkorder(a, b) || a.last == -1)
		exit(0);
	ft_index(&a);
	ft_tsort(a, b);
	free(a.arr);
	free(b.arr);
	return (0);
}

// void	ft_qsort_to_b(t_stack *a, t_stack *b)
// {
// 	int		i;
// 	int		j;
// 	int		count;
// 	int		min;
// 	int		imin;
// 	int		median;

// 	j = 0;
// 	median = a->size - 1 - (a->last / 2);
// 	while (j < a->last)
// 	{
// 		i = 0;
// 		min = 2147483647;
// 		while (a->arr[i]) // цикл в итоге перекинет меньше медианы
// 		{
// 			if (a->arr[i] < median)
// 			{
// 				count = ft_instrcount(*a, *b, i);
// 				if (count < min)
// 				{
// 					min = count;
// 					imin = i;
// 				}
// 				// считаем количество необходимых перестановок, выбираем мин и перебрасываем
// 			}
// 			i++;
// 		}
// 		ft_send_to_another(a, b, imin);
// 		j++;
// 	}
// 	if (a->last >= 3)
// 		ft_qsort_to_b(a, b);
// }

// void	ft_qsort(t_stack *a, t_stack *b)
// {
// 	// такой же цикл для б, возможно разложить в 2 функции, тип оставить в этой только условия ниже
// 	if (a->last >= 3)
// 	{
// 		ft_qsort_to_b(a, b);
// 	}
// 	ft_showstack(*a);
// 	ft_showstack(*b);
// 	if (a->last < 3)
// 	{
		 
// 	}
// 	if (b->last != -1)
// 	{
//		//  снова qsort() для б
// 	}
// }
