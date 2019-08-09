/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:22:20 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 22:56:34 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putargv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ft_putendl(argv[i]);
		i++;
	}
}

char	**ft_initargv(int argc, char *argv[])
{
	int		strsize;
	char	*str;
	int		i;

	i = 1;
	strsize = 0;
	while (i < argc)
		strsize += ft_strlen(argv[i++]);
	if (!(str = (char*)malloc(strsize + argc + 1)))
		exit(0);
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i++]);
		ft_strcat(str, " ");
	}
	str[ft_strlen(str)] = '\0';
	argv = ft_strsplit(str, ' ');
	free(str);
	return (argv);
}

size_t	ft_spacecount(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	ft_stackinit(t_stack *a, t_stack *b, int *argc, char ***argv)
{
	int i;

	i = 1;
	if (*argc == 1)
		exit(0);
	while ((*argv)[i])
	{
		if (!ft_isprint((*argv)[i][0])
	|| ft_strlen((*argv)[i]) == ft_spacecount((*argv)[i]))
			ft_error();
		i++;
	}
	*argv = ft_initargv(*argc, *argv);
	*argc = 0;
	while ((*argv)[*argc])
		(*argc)++;
	(*argc)++;
	a->size = *argc - 1;
	b->size = *argc - 1;
	if (!(a->arr = (int*)malloc(4 * a->size))
	|| !(b->arr = (int*)malloc(4 * b->size)))
		exit(0);
	a->last = -1;
	b->last = -1;
}

void	ft_initstacka(t_stack *a, int argc, char *argv[])
{
	char	*checkintrange;

	checkintrange = NULL;
	a->last++;
	argc -= 2;
	while (a->last < a->size)
	{
		a->arr[a->last] = ft_atoi(argv[argc - a->last]);
		if (ft_checkarg(argv[argc - a->last])
		|| ft_checkduplicate(*a))
			ft_error();
		if (ft_strlen(argv[argc - a->last]) > 9)
		{
			checkintrange = ft_itoa(a->arr[a->last]);
			if (ft_strcmp(checkintrange, argv[argc - a->last]))
				ft_error();
			free(checkintrange);
		}
		free(argv[argc - a->last]);
		a->last++;
	}
	free(argv);
	a->last--;
}
