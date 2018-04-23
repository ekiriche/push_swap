/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:19:58 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:20:06 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_sort(t_stack *s, t_flags *f)
{
	int		count;

	count = 0;
	while (!if_sorted(s))
	{
		if (if_first_smallest(s))
			do_all("pb", &count, s, f);
		else if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
			do_all("sa", &count, s, f);
		else if (smallest_side(s) == 2)
			do_all("rra", &count, s, f);
		else if (smallest_side(s) == 1)
			do_all("ra", &count, s, f);
	}
	while (s->top_b - 1 >= 0)
		do_all("pa", &count, s, f);
	if (f->flag_count == 1)
		ft_printf("Total number of operations = %d\n", count);
}

void	sort_step_2(t_stack *s, t_flags *f, int *count)
{
	sort_a(s, count, f);
	while (s->top_b > 0)
	{
		find_max(s);
		find_min(s);
		push_to_a(s, count, f);
	}
	if (smallest_side(s) == 1)
		while (!if_sorted(s))
			do_all("ra", count, s, f);
	else
		while (!if_sorted(s))
			do_all("rra", count, s, f);
	if (f->flag_count == 1)
		ft_printf("Total number of operations = %i.\n", *count);
}

void	sort_step_1(t_stack *s, t_flags *f, t_crappy_code *c)
{
	if (c->flag >= 1 && s->size >= 400)
	{
		while (c->i >= 0 && s->top_a > 3 && !if_sorted(s))
		{
			if (s->stack_a[c->i] < c->temp / 2)
			{
				push_to_b(s, c->i, &c->count, f);
				c->i = s->top_a - 1;
			}
			else
				c->i--;
		}
		c->flag--;
	}
	while (c->i >= 0)
	{
		if (s->stack_a[c->i] < c->temp)
		{
			push_to_b(s, c->i, &c->count, f);
			c->i = s->top_a - 1;
		}
		else
			c->i--;
	}
}

void	main_sort(t_stack *s, t_flags *f)
{
	t_crappy_code *c;

	c = (t_crappy_code*)malloc(sizeof(t_crappy_code));
	c->count = 0;
	c->flag = 3;
	while (s->top_a > 3 && !if_sorted(s))
	{
		c->temp = s->stack_a[find_median_a(s)];
		c->i = s->top_a - 1;
		sort_step_1(s, f, c);
	}
	sort_step_2(s, f, &c->count);
}
