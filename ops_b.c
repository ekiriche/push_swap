/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:02:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 12:02:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sb(t_stack *s)
{
	int		tmp;

	if (s->top_b <= 1)
		return ;
	tmp = s->stack_b[s->top_b - 1];
	s->stack_b[s->top_b - 1] = s->stack_b[s->top_b - 2];
	s->stack_b[s->top_b - 2] = tmp;
}

void		pb(t_stack *s)
{
	if (s->top_a == 0)
		return ;
	push_b(s, pop_a(s));
}

void		rb(t_stack *s)
{
	int		i;
	int		tmp;

	i = 0;
	while (s->top_b - i - 2 >= 0)
	{
		tmp = s->stack_b[s->top_b - i - 1];
		s->stack_b[s->top_b - i - 1] = s->stack_b[s->top_b - i - 2];
		s->stack_b[s->top_b - i - 2] = tmp;
		i++;
	}
}

void		rrb(t_stack *s)
{
	int		i;
	int		tmp;

	i = 0;
	while (i + 1 < s->top_b)
	{
		tmp = s->stack_b[i + 1];
		s->stack_b[i + 1] = s->stack_b[i];
		s->stack_b[i] = tmp;
		i++;
	}
}