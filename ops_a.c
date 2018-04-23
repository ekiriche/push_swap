/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:01:13 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 12:01:25 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stack *s)
{
	int		tmp;

	if (s->top_a <= 1)
		return ;
	else
	{
		tmp = s->stack_a[s->top_a - 1];
		s->stack_a[s->top_a - 1] = s->stack_a[s->top_a - 2];
		s->stack_a[s->top_a - 2] = tmp;
	}
}

void		pa(t_stack *s)
{
	if (s->top_b == 0)
		return ;
	push_a(s, pop_b(s));
}

void		ra(t_stack *s)
{
	int		i;
	int		tmp;

	i = 0;
	while (s->top_a - i - 2 >= 0)
	{
		tmp = s->stack_a[s->top_a - i - 1];
		s->stack_a[s->top_a - i - 1] = s->stack_a[s->top_a - i - 2];
		s->stack_a[s->top_a - i - 2] = tmp;
		i++;
	}
}

void		rra(t_stack *s)
{
	int		i;
	int		tmp;

	i = 0;
	while (i + 1 < s->top_a)
	{
		tmp = s->stack_a[i + 1];
		s->stack_a[i + 1] = s->stack_a[i];
		s->stack_a[i] = tmp;
		i++;
	}
}
