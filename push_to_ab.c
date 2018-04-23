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
		{
			rra(s);
			*count += 1;
			print_s(s, "rra", f);
		}
		pb(s);
		*count += 1;
		print_s(s, "pb", f);
	}
	else
	{
		while (s->stack_a[s->top_a - 1] != temp)
		{
			ra(s);
			*count += 1;
			print_s(s, "ra", f);
		}
		pb(s);
		*count += 1;
		print_s(s, "pb", f);
	}	
}

void	sort_a(t_stack *s, int *count, t_flags *f)
{
	int i;

	i = 0;
	while (!if_sorted(s))
	{
		if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
		{
			sa(s);
			*count += 1;
			print_s(s, "sa", f);
		}
		else
		{
			rra(s);
			*count += 1;
			print_s(s, "rra", f);
		}
	}
}

void	push_to_a(t_stack *s, int *count, t_flags *f)
{
	if (s->b_max_idx >= s->top_b / 2)
		while (s->stack_b[s->top_b - 1] != s->b_max && s->stack_b[s->top_b - 1] != s->b_min)
		{
			rb(s);
			*count += 1;
			print_s(s, "rb", f);
		}
	else
		while (s->stack_b[s->top_b - 1] != s->b_max && s->stack_b[s->top_b - 1] != s->b_min)
		{
			rrb(s);
			*count += 1;
			print_s(s, "rrb", f);
		}
	if (s->stack_b[s->top_b - 1] == s->b_min)
	{
		pa(s);
		print_s(s, "pa", f);
		ra(s);
		print_s(s, "ra", f);
		*count += 2;
	}
	else
	{
		pa(s);
		print_s(s, "pa", f);
		*count += 1;
	}
}
