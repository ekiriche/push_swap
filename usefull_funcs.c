/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:16:53 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:17:00 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	look_for_flags(char **str, t_flags *f)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_strcmp(str[i], "-v") == 0)
		{
			f->flag_v = 1;
			count++;
		}
		if (ft_strcmp(str[i], "-c") == 0)
		{
			count++;
			f->flag_color = 1;
		}
		if (ft_strcmp(str[i], "-i") == 0)
		{
			count++;
			f->flag_count = 1;
		}
		i++;
	}
	return (count);
}

int 	len_of_arrays(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		find_median_a(t_stack *s)
{
	int		idx1;
	int 	idx2;
	int 	count_smaller;
	int 	count_bigger;

	idx1 = 0;
	while (idx1 < s->top_a)
	{
		idx2 = 0;
		count_smaller = 0;
		count_bigger = 0;
		while (idx2 < s->top_a)
		{
			if (s->stack_a[idx1] < s->stack_a[idx2])
				count_smaller++;
			else if (s->stack_a[idx1] > s->stack_a[idx2])
				count_bigger++;
			idx2++;
		}
		if (s->top_a % 2 == 1 && count_smaller == count_bigger)
			return (idx1);
		else if (s->top_a % 2 == 0 && count_smaller + 1 == count_bigger)
			return (idx1);
		idx1++;
	}
	return (-42);
}