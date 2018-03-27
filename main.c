/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/03/27 14:04:59 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack, int data)
{
	if (stack->top_a == stack->size)
		ft_printf("%s\n", "Overflow");
	else
	{
		stack->stack_a[stack->top_a] = data;
		stack->top_a += 1;
	}
}

int		pop_a(t_stack *stack)
{
	int	data;

	if (stack->top_a == 0)
		ft_printf("%s\n", "Underflow");
	else
	{
		stack->top_a -= 1;
		data = stack->stack_a[stack->top_a];
	}
	return (data);
}

void	push_b(t_stack *stack, int data)
{
	if (stack->top_b == stack->size)
		ft_printf("%s\n", "Overflow");
	else
	{
		stack->stack_b[stack->top_b] = data;
		stack->top_b += 1;
	}
}

int		pop_b(t_stack *stack)
{
	int	data;

	if (stack->top_b == 0)
		ft_printf("%s\n", "Underflow");
	else
	{
		stack->top_b -= 1;
		data = stack->stack_b[stack->top_b];
	}
	return (data);
}

t_stack		*initialize(int size)
{
	t_stack		*ans;

	ans = (t_stack*)malloc(sizeof(t_stack));
	ans->size = size - 1;
	ans->top_a = 0;
	ans->top_b = 0;
	ans->stack_b = (int*)malloc(sizeof(int) * (ans->size));
	ans->stack_a = (int*)malloc(sizeof(int) * (ans->size));

	return (ans);
}

void		sa(t_stack *s)
{
	int		tmp;

	if (s->top_a <= 1)
		ft_printf("%s\n", "Not enough data");
	else
	{
		tmp = s->stack_a[s->top_a - 1];
		s->stack_a[s->top_a - 1] = s->stack_a[s->top_a - 2];
		s->stack_a[s->top_a - 2] = tmp;
	}
}

void		sb(t_stack *s)
{
	int		tmp;

	if (s->top_b <= 1)
		return ;
	tmp = s->stack_b[s->top_b - 1];
	s->stack_b[s->top_b - 1] = s->stack_b[s->top_b - 2];
	s->stack_b[s->top_b - 2] = tmp;
}

void		ss(t_stack *s)
{
	sa(s);
	sb(s);
}

void		pa(t_stack *s)
{
	if (s->top_b == 0)
		return ;
	push_a(s, pop_b(s));
}

void		pb(t_stack *s)
{
	if (s->top_a == 0)
		return ;
	push_b(s, pop_a(s));
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

void		rr(t_stack *s)
{
	ra(s);
	rb(s);
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

void		rrr(t_stack *s)
{
	rra(s);
	rrb(s);
}

void		destroy_stack(t_stack *stack)
{
	ft_memdel((void**)&stack->stack_a);
	ft_memdel((void**)&stack->stack_b);
	ft_memdel((void**)&stack);
}

void	print_s(t_stack *s, char *oper)
{
	int		i;

	i = s->top_a - 1;
	ft_printf("Exec %s:\n", oper);
	ft_printf("%s", "a --> ");
	while (i >= 0)
	{
		ft_printf("%i ", s->stack_a[i]);
		i--;
	}
	ft_printf("\n");
	ft_printf("%s", "b --> ");
	i = s->top_b - 1;
	while (i >= 0)
	{
		ft_printf("%i ", s->stack_b[i]);
		i--;
	}
	ft_printf("\n------------------------------------------\n");
}

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
}

void	lets_sort(t_stack *s)
{
	int		count;

	count = 0;
	while (!if_sorted(s))
	{
		if (if_first_smallest(s))
		{
			pb(s);
			count++;
			//			print_s(s, "pb");
		}
		else if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
		{
			sa(s);
			count++;
			//			print_s(s, "sa");
		}
		else if (smallest_side(s) == 2)
		{
			rra(s);
			count++;
			//			print_s(s, "rra");
		}
		else if (smallest_side(s) == 1)
		{
			ra(s);
			count++;
			//			print_s(s, "ra");
		}
	}
	while (s->top_b - 1 >= 0)
	{
		pa(s);
		count++;
		//		print_s(s, "pa");
	}
	ft_printf("%d\n", count);
}

void	put_max_on_top(t_stack *s, int *count)
{
	if (s->b_max_idx >= s->top_b / 2)
		while (s->stack_b[s->top_b - 1] != s->b_max)
		{
			rb(s);
			*count += 1;
			print_s(s, "rb");
		}
	else
		while (s->stack_b[s->top_b - 1] != s->b_max)
		{
			rrb(s);
			*count += 1;
			print_s(s, "rrb");
		}
}

int		find_place_to_place(t_stack *s)
{
	int	i;
	int	ans;

	i = 0;
	ans = s->top_b - 1;
	while (s->top_b - 1 - i >= 0)
	{
		if (s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1 - i])
		{
			ans = s->top_b - 1 - i;
			break ;
		}
		i++;
	}
	return (ans);
}

void	do_some_rotations(t_stack *s, int *count)
{
	int		i;
	int		j;

	i = find_place_to_place(s);
	if (s->top_b % 2 == 1)
		j = s->top_b + 1;
	else
		j = s->top_b;
	if (i >= j / 2)
	{
		while (s->stack_a[s->top_a - 1] < s->stack_b[s->top_b - 1] ||
				s->stack_a[s->top_a - 1] > s->stack_b[0])
		{
			rb(s);
			*count += 1;
			print_s(s, "rb");
		}
	}
	else
	{
		while (s->stack_a[s->top_a - 1] < s->stack_b[s->top_b - 1] ||
				s->stack_a[s->top_a - 1] > s->stack_b[0])
		{
			rrb(s);
			*count += 1;
			print_s(s, "rrb");
		}
	}
}

void	do_some_jokes(t_stack *s, int *count)
{
	int		i;
	int		j;

	j = find_place_to_place(s);
	if (s->top_b % 2 == 1)
		i = s->top_b + 1;
	else
		i = s->top_b;
	if (j > i)
	{
		while (s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1]
			&& s->stack_a[s->top_a - 1] > s->stack_b[0])
			{
				rb(s);
				*count += 1;
				print_s(s, "rb");
			}
	}
	else
	{
		while(s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1]
			&& s->stack_a[s->top_a - 1] > s->stack_b[0])
		{
			rrb(s);
			*count += 1;
			print_s(s, "rrb");
		}
	}
}

void	optimizer_v2(t_stack *s, int *count)
{
	int		diff1;
	int		diff2;

	if (s->top_a == 1)
		return ;
	diff1 = s->stack_a[s->top_a - 1] - s->stack_b[s->top_b - 1];
	if (diff1 < 0)
		diff1 = -diff1;
	diff2 = s->stack_a[0] - s->stack_b[s->top_b - 1];
	if (diff2 < 0)
		diff2 = -diff2;
	if (diff1 > diff2)
	{
		rra(s);
		print_s(s, "rra");
		*count += 1;
	}
}

void	optimizer_v1(t_stack *s, int *count)
{
	int		diff1;
	int		diff2;

	if (s->top_a == 1)
		return ;
	diff1 = s->stack_a[s->top_a - 1] - s->stack_b[s->top_b - 1];
	if (diff1 < 0)
		diff1 = -diff1;
	diff2 = s->stack_a[s->top_a - 2] - s->stack_b[s->top_b - 1];
	if (diff2 < 0)
		diff2 = -diff2;
	if (diff1 > diff2)
	{
		sa(s);
		print_s(s, "sa");
		*count += 1;
	}
	else
		optimizer_v2(s, count);
}

void	big_sort(t_stack *s)
{
	int		count;

	count = 0;
	if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
	{
		sa(s);
		count++;
		print_s(s, "sa");
	}
	pb(s);
	print_s(s, "pb");
	pb(s);
	print_s(s, "pb");
	count += 2;
	while (s->top_a != 0)
	{
		find_min(s);
		find_max(s);
		optimizer_v1(s, &count);
		if (s->stack_a[s->top_a - 1] > s->b_max ||
			s->stack_a[s->top_a - 1] < s->b_min)
		{
			put_max_on_top(s, &count);
			pb(s);
			print_s(s, "pb");
			count++;
		}
		else if (s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1]
		&& s->stack_a[s->top_a - 1] < s->stack_b[0])
		{
			pb(s);
			count++;
			print_s(s, "pb");
		}
		else if (s->stack_a[s->top_a - 1] < s->stack_b[s->top_b - 1])
		{
			do_some_rotations(s, &count);
			pb(s);
			print_s(s, "pb");
			count++;
		}
		else if (s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1]
		&& s->stack_a[s->top_a - 1] > s->stack_b[s->top_b - 1])
		{
			do_some_jokes(s, &count);
			pb(s);
			print_s(s, "pb");
			count++;
		}
	}
	find_max(s);
	while (s->stack_b[s->top_b - 1] != s->b_max)
	{
		rb(s);
		count++;
		print_s(s, "rb");
	}
	while (s->top_b)
	{
		pa(s);
		count++;
		print_s(s, "pa");
	}
	ft_printf("%d\n", count);
}

int		main(int argc, char **argv)
{
	t_stack		*stack;
	int			i;


	if (argc < 2)
		return (0);
	i = 1;
	stack = initialize(argc);
	while (argc - i > 0)
	{
		push_a(stack, ft_atoi(argv[argc - i]));
		i++;
	}
//	if (argc < 10)
//		lets_sort(stack);
//	else
		big_sort(stack);
	find_min(stack);
	find_max(stack);
//	put_max_on_top(stack);
	destroy_stack(stack);
	exit (0);
}
