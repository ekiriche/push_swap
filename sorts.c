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
		{
			pb(s);
			count++;
			print_s(s, "pb", f);
		}
		else if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
		{
			sa(s);
			count++;
			print_s(s, "sa", f);
		}
		else if (smallest_side(s) == 2)
		{
			rra(s);
			count++;
			print_s(s, "rra", f);
		}
		else if (smallest_side(s) == 1)
		{
			ra(s);
			count++;
			print_s(s, "ra", f);
		}
	}
	while (s->top_b - 1 >= 0)
	{
		pa(s);
		count++;
		print_s(s, "pa", f);
	}
	if (f->flag_count == 1)
		ft_printf("Total number of operations = %d\n", count);
}

void	main_sort(t_stack *s, t_flags *f)
{
	int temp;
	int i;
	int count;

	count = 0;
	int flag = 3;
	while (s->top_a > 3 && !if_sorted(s))
	{
		temp = s->stack_a[find_median_a(s)];
		i = s->top_a - 1;
		if (flag >= 1 && s->size >= 400)
		{
			while (i >= 0 && s->top_a > 3 && !if_sorted(s))
		{
			if (s->stack_a[i] < temp / 2)
			{
				push_to_b(s, i, &count, f);
				i = s->top_a - 1;
			}
			else
				i--;
		}
		flag--;
		}
		while (i >= 0)
		{
			if (s->stack_a[i] < temp)
			{
				push_to_b(s, i, &count, f);
				i = s->top_a - 1;
			}
			else
				i--;
		}
	}
	sort_a(s, &count, f);
	while (s->top_b > 0)
	{
		find_max(s);
		find_min(s);
		push_to_a(s, &count, f);
	}
	if (smallest_side(s) == 1)
	{
		while (!if_sorted(s))
		{
			ra(s);
			count++;
			print_s(s, "ra", f);
		}
	}
	else
	{
		while (!if_sorted(s))
		{
			rra(s);
			print_s(s, "rra", f);
			count++;
		}
	}
	if (f->flag_count == 1)
		ft_printf("Total number of operations = %i.\n", count);
}