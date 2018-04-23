/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:16:53 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 18:12:06 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_all(char *op, int *count, t_stack *s, t_flags *f)
{
	if (ft_strcmp(op, "pa") == 0)
		pa(s);
	else if (ft_strcmp(op, "sa") == 0)
		sa(s);
	else if (ft_strcmp(op, "pb") == 0)
		pb(s);
	else if (ft_strcmp(op, "ra") == 0)
		ra(s);
	else if (ft_strcmp(op, "rb") == 0)
		rb(s);
	else if (ft_strcmp(op, "rra") == 0)
		rra(s);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(s);
	*count += 1;
	print_s(s, op, f);
}

int		look_for_flags(char **str, t_flags *f)
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

int		len_of_arrays(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		find_median_a(t_stack *s)
{
	int	idx1;
	int	idx2;
	int	count_smaller;
	int	count_bigger;

	idx1 = 0;
	while (idx1 < s->top_a)
	{
		idx2 = -1;
		count_smaller = 0;
		count_bigger = 0;
		while (++idx2 < s->top_a)
		{
			if (s->stack_a[idx1] < s->stack_a[idx2])
				count_smaller++;
			else if (s->stack_a[idx1] > s->stack_a[idx2])
				count_bigger++;
		}
		if (s->top_a % 2 == 1 && count_smaller == count_bigger)
			return (idx1);
		else if (s->top_a % 2 == 0 && count_smaller + 1 == count_bigger)
			return (idx1);
		idx1++;
	}
	return (-42);
}

void	do_command(t_stack *s, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(s);
	else if (ft_strcmp(line, "ra") == 0)
		ra(s);
	else if (ft_strcmp(line, "rra") == 0)
		rra(s);
	else if (ft_strcmp(line, "pa") == 0)
		pa(s);
	else if (ft_strcmp(line, "sb") == 0)
		sb(s);
	else if (ft_strcmp(line, "rb") == 0)
		rb(s);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(s);
	else if (ft_strcmp(line, "pb") == 0)
		pb(s);
	else if (ft_strcmp(line, "ss") == 0)
		ss(s);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(s);
	else if (ft_strcmp(line, "rr") == 0)
		rr(s);
	else
		error();
}
