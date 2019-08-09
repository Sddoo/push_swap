/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:55:41 by hfrankly          #+#    #+#             */
/*   Updated: 2019/08/09 19:06:14 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>

typedef struct s_stack t_stack;

struct s_stack
{
    int		*arr;
	int		last;
	int		size;
};

//inits.c
void	ft_stackinit(t_stack *a, t_stack *b, int *argc, char ***argv);
void	ft_initstacka(t_stack *a, int argc, char *argv[]);
char	**ft_initargv(int argc, char *argv[]);
//main.c
int		ft_checkoper(t_stack *a, t_stack *b);
void	ft_checkoper2(t_stack *a, t_stack *b, char *str);
int		ft_checkorder(t_stack a, t_stack b);
void	ft_showstack(t_stack stck);
void	ft_showstacks(t_stack stck, t_stack stck1);
//errors.c
void	ft_error();
int		ft_checkduplicate(t_stack a);
int		ft_checkarg(char *str);
//instructions.c
void	ft_swap(t_stack *stck);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_rot(t_stack *stck);
void	ft_revrot(t_stack *stck);
//ssort.c
void	ft_ssort_b(t_stack *a, t_stack *b, int i);
void	ft_ssort(t_stack a, t_stack b);
//main.c
void	ft_fillstack(t_stack *src, t_stack *dst, char *str);
int		ft_getimin(t_stack *stck);
void	ft_send_to_another(t_stack *src, t_stack *dst, int i);
int		ft_instrcount(t_stack src, t_stack dst, int i);
void	ft_qsort_to_b(t_stack *a, t_stack *b);
void	ft_qsort(t_stack *a, t_stack *b);
void	ft_index(t_stack *a);

#endif

// придумать новый способ проверки диапозона инта, 000000000000006,
// не забыть изменить checker под ТЗ: Once all the instructions have been read, 
// почини свой gnl
// изменить поиск минимального

// if ((((int)(a->arr[a->last]) + (a->arr[a->last])) / 2 != (a->arr[a->last])))
