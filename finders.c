/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:04:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:04:34 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		if_sorted(t_stack *s)
{
	int		i;

	i = 0;
	while (i + 1 < s->top_a)
	{
		if (s->stack_a[i] < s->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		if_first_smallest(t_stack *s)
{
	int		i;

	i = 0;
	while (s->top_a - 2 - i >= 0 && s->stack_a[s->top_a - 1] <
			s->stack_a[s->top_a - 2 - i])
		i++;
	if (i == s->top_a - 1)
		return (1);
	return (0);
}

int		smallest_side(t_stack *s)
{
	int		i;
	int		ans;

	i = s->top_a - 1;
	ans = i;
	while (i - 1 >= 0)
	{
		if (s->stack_a[ans] > s->stack_a[i - 1])
			ans = i - 1;
		i--;
	}
	if (s->top_a % 2 == 1)
	{
		if (ans >= (s->top_a + 1) / 2 - 1)
			return (1);
		else
			return (2);
	}
	if (ans >= (s->top_a) / 2 - 1)
		return (1);
	else
		return (2);
}

void	find_min(t_stack *s)
{
	int		i;

	i = 0;
	s->b_min = s->stack_b[s->top_b - 1];
	s->b_min_idx = s->top_b - 1;
	while (s->top_b - 2 - i >= 0)
	{
		if (s->b_min > s->stack_b[s->top_b - i - 2])
		{
			s->b_min = s->stack_b[s->top_b - i - 2];
			s->b_min_idx = s->top_b - i - 2;
		}
		i++;
	}
	i = 0;
	s->a_min = s->stack_a[s->top_a - 1];
	s->a_min_idx = s->top_a - 1;
	while (s->top_a - 2 - i >= 0)
	{
		if (s->a_min > s->stack_a[s->top_a - i - 2])
		{
			s->a_min = s->stack_a[s->top_a - i - 2];
			s->a_min_idx = s->top_a - i - 2;
		}
		i++;
	}
}

void	find_max(t_stack *s)
{
	int		i;

	i = 0;
	s->b_max = s->stack_b[s->top_b - 1];
	s->b_max_idx = s->top_b - 1;
	while (s->top_b - 2 - i >= 0)
	{
		if (s->b_max < s->stack_b[s->top_b - i - 2])
		{
			s->b_max = s->stack_b[s->top_b - i - 2];
			s->b_max_idx = s->top_b - i - 2;
		}
		i++;
	}
	i = 0;
	s->a_max = s->stack_a[s->top_a - 1];
	s->a_max_idx = s->top_a - 1;
	while (s->top_a - 2 - i >= 0)
	{
		if (s->a_max < s->stack_a[s->top_a - i - 2])
		{
			s->a_max = s->stack_a[s->top_a - i - 2];
			s->a_max_idx = s->top_a - i - 2;
		}
		i++;
	}
}