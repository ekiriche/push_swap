/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:18:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 14:07:06 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *s, int idx, int *count, t_flags *f)
{
	int temp;

	temp = s->stack_a[idx];
	find_min(s);
	if (idx < s->top_a / 2)
	{
		while (s->stack_a[s->top_a - 1] != temp)
			do_all("rra", count, s, f);
		do_all("pb", count, s, f);
	}
	else
	{
		while (s->stack_a[s->top_a - 1] != temp)
			do_all("ra", count, s, f);
		do_all("pb", count, s, f);
	}
}

void	sort_a(t_stack *s, int *count, t_flags *f)
{
	int i;

	i = 0;
	while (!if_sorted(s))
	{
		if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
			do_all("sa", count, s, f);
		else
			do_all("rra", count, s, f);
	}
}

void	push_to_a(t_stack *s, int *count, t_flags *f)
{
	if (s->b_max_idx >= s->top_b / 2)
		while (s->stack_b[s->top_b - 1] != s->b_max &&
			s->stack_b[s->top_b - 1] != s->b_min)
			do_all("rb", count, s, f);
	else
		while (s->stack_b[s->top_b - 1] != s->b_max &&
			s->stack_b[s->top_b - 1] != s->b_min)
			do_all("rrb", count, s, f);
	if (s->stack_b[s->top_b - 1] == s->b_min)
	{
		do_all("pa", count, s, f);
		do_all("ra", count, s, f);
	}
	else
		do_all("pa", count, s, f);
}
