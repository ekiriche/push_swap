/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:40:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/20 12:59:29 by ekiriche         ###   ########.fr       */
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

int 	len_of_arrays(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	error()
{
	write(2, "Error\n", 6);
	exit (0);
}

int 	if_empty(int *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (1);
	return (0);
}

void	actualy_sort(t_stack *s)
{
	char *line;
	int i = 0;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			sa(s);
		else if (ft_strcmp(line, "ra") == 0)
			ra(s);
		else if (ft_strcmp(line, "rra") == 0)
			rra(s);
		else if (ft_strcmp(line, "pa") == 0)
			pa(s);
		else if (ft_strcmp(line, "sb") == 0)
			sb(s);
		else if (ft_strcmp(line, "rb") == 0)
			rb(s);
		else if (ft_strcmp(line, "rrb") == 0)
			rrb(s);
		else if (ft_strcmp(line, "pb") == 0)
			pb(s);
		else if (ft_strcmp(line, "ss") == 0)
			ss(s);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(s);
		else if (ft_strcmp(line, "rr") == 0)
			rr(s);
		else 
			error();
		ft_memdel((void**)&line);
	}
	if (if_sorted(s) && s->top_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	handle_one_param_check(t_stack *s, char *str)
{
	char **ans;
	int i;
	int l;

	ans = ft_strsplit(str, ' ');
	i = len_of_arrays(ans) - 1;
	s = initialize(i + 2);
	while (i >= 0)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(ans[i])), ans[i]) != 0)
			error();
		l = 1;
		while (i - l > 1)
		{
			if (ft_atoi(ans[i]) == ft_atoi(ans[i - l]))
				error();
			l++;
		}
		push_a(s, ft_atoi(ans[i]));
		i--;
	}
	actualy_sort(s);
}

int 	main(int argc, char **argv)
{
	t_stack *s;
	int i;
	int l;

	i = 1;
	if (argc == 2)
		handle_one_param_check(s, argv[1]);
	else
	{
		s = initialize(argc);
		while (argc - i > 0)
		{
			if (ft_strcmp(ft_itoa(ft_atoi(argv[argc - i])), argv[argc - i]) != 0)
				error();
			l = 1;
			while (argc - i - l > 0)
			{
				if (ft_atoi(argv[argc - i]) == ft_atoi(argv[argc - i - l]))
					error();
				l++;
			}
			push_a(s, ft_atoi(argv[argc - i]));
			i++;
		}
		actualy_sort(s);
	}
	return (1);
}
