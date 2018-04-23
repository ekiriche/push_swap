/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:12:11 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:12:20 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_s(t_stack *s, char *oper, t_flags *f)
{
	int		i;

	if (f->flag_v != 1)
	{
		ft_printf("%s\n", oper);
		return ;
	}
	i = s->top_a - 1;
	ft_printf("Exec %s:\n", oper);
	ft_printf("%s", "a --> ");
	while (i >= 0)
	{
		if (f->flag_color == 1 && i == s->top_a - 1 && ft_strcmp(oper, "pa") == 0)
			ft_printf("%s%i%s ", "\x1B[31m", s->stack_a[i], "\x1B[0m");
		else if (f->flag_color == 1 && (i == s->top_a - 1 || i == s->top_a - 2) &&
			ft_strcmp(oper, "sa") == 0)
			ft_printf("%s%i%s ", "\x1B[31m", s->stack_a[i], "\x1B[0m");
		else if (f->flag_color == 1 && (ft_strcmp(oper, "ra") == 0 || ft_strcmp(oper, "rra") == 0))
			ft_printf("%s%i%s ", "\x1B[36m", s->stack_a[i], "\x1B[0m");
		else
			ft_printf("%i ", s->stack_a[i]);
		i--;
	}
	ft_printf("\n");
	ft_printf("%s", "b --> ");
	i = s->top_b - 1;
	while (i >= 0)
	{
		if (f->flag_color == 1 && i == s->top_b - 1 && ft_strcmp(oper, "pb") == 0)
			ft_printf("%s%i%s ", "\x1B[31m", s->stack_b[i], "\x1B[0m");
		else if (f->flag_color == 1 && (ft_strcmp(oper, "rb") == 0 || ft_strcmp(oper, "rrb") == 0))
			ft_printf("%s%i%s ", "\x1B[36m", s->stack_b[i], "\x1B[0m");
		else
			ft_printf("%i ", s->stack_b[i]);
		i--;
	}
	ft_printf("\n------------------------------------------\n");
}