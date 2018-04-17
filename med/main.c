/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/17 12:28:04 by ekiriche         ###   ########.fr       */
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
			print_s(s, "pb");
		}
		else if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
		{
			sa(s);
			count++;
			print_s(s, "sa");
		}
		else if (smallest_side(s) == 2)
		{
			rra(s);
			count++;
			print_s(s, "rra");
		}
		else if (smallest_side(s) == 1)
		{
			ra(s);
			count++;
			print_s(s, "ra");
		}
	}
	while (s->top_b - 1 >= 0)
	{
		pa(s);
		count++;
		print_s(s, "pa");
	}
	ft_printf("%d\n", count);
}

int		find_median_a(t_stack *s)
{
	int		idx1;
	int 	idx2;
	int 	count_smaller;
	int 	count_bigger;

	idx1 = 0;
	while (idx1 < s->top_a)
	{
		idx2 = 0;
		count_smaller = 0;
		count_bigger = 0;
		while (idx2 < s->top_a)
		{
			if (s->stack_a[idx1] < s->stack_a[idx2])
				count_smaller++;
			else if (s->stack_a[idx1] > s->stack_a[idx2])
				count_bigger++;
			idx2++;
		}
//		ft_printf("%i %i\n", count_smaller, count_bigger);
		if (s->top_a % 2 == 1 && count_smaller == count_bigger)
			return (idx1);
		else if (s->top_a % 2 == 0 && count_smaller + 1 == count_bigger)
			return (idx1);
		idx1++;
	}
	return (-42);
}

void	push_to_b(t_stack *s, int idx, int *count)
{
	int temp;

	temp = s->stack_a[idx];
	find_min(s);
	int temp2 = s->a_min;
	if (idx < s->top_a / 2)
	{
		while (s->stack_a[s->top_a - 1] != temp)
		{
			rra(s);
			*count += 1;
//			print_s(s, "ra");
		}
		pb(s);
		*count += 1;
//		print_s(s, "pb");
	}
	else
	{
		while (s->stack_a[s->top_a - 1] != temp)
		{
			ra(s);
			*count += 1;
//			print_s(s, "ra");
		}
		pb(s);
		*count += 1;
//		print_s(s, "pb");		
	}	
}

void	sort_a(t_stack *s, int *count)
{
	int i;

	i = 0;
	while (!if_sorted(s))
	{
		if (s->stack_a[s->top_a - 1] > s->stack_a[s->top_a - 2])
		{
			sa(s);
			*count += 1;
//			print_s(s, "sa");
		}
		else
		{
			rra(s);
			*count += 1;
//			print_s(s, "rra");
		}
	}
}

void	push_to_a(t_stack *s, int *count)
{
	static int there = 0;

	if (s->b_max_idx >= s->top_b / 2)
		while (s->stack_b[s->top_b - 1] != s->b_max && s->stack_b[s->top_b - 1] != s->b_min)
		{
			rb(s);
			there++;
			*count += 1;
//			print_s(s, "rb");
		}
	else
		while (s->stack_b[s->top_b - 1] != s->b_max && s->stack_b[s->top_b - 1] != s->b_min)
		{
			rrb(s);
			there++;
			*count += 1;
//			print_s(s, "rrb");
		}
	if (s->stack_b[s->top_b - 1] == s->b_min)
	{
		pa(s);
		ra(s);
		*count += 2;
		there += 2;
	}
	else
	{
		pa(s);
//		print_s(s, "pa");
		*count += 1;
		there++;
	}
	printf("%d\n", there);
}

void	main_sort(t_stack *s)
{
	int temp;
	int i;
	int count;

	count = 0;
	while (s->top_a > 3 && !if_sorted(s))
	{
		temp = s->stack_a[find_median_a(s)];
		i = s->top_a - 1;
		while (i >= 0)
		{
			if (s->stack_a[i] < temp)
			{
				push_to_b(s, i, &count);
				i = s->top_a - 1;
			}
			else
				i--;
		}
	}
	sort_a(s, &count);
	while (s->top_b > 0)
	{
		find_max(s);
		find_min(s);
		push_to_a(s, &count);
	}
	while (!if_sorted(s))
	{
		rra(s);
		count++;
	}
	print_s(s, "none");
	printf("%i\n", count);
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
	ft_putstr("\x1B[31m");
	ft_putstr("dude");
	ft_putstr("\x1B[0m");
//	main_sort(stack);
	destroy_stack(stack);
	exit (0);
}
