/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/18 14:57:49 by ekiriche         ###   ########.fr       */
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
			print_s(s, "ra", f);
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

t_flags	*initialize_flags()
{
	t_flags *flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->flag_v = 0;
	flags->flag_color = 0;
	flags->flag_count = 0;
	return (flags);
}

void	error()
{
	write(2, "Error\n", 6);
	exit (0);
}

void	look_for_errors(int argc, char **argv)
{
	int i;
	int l;
	char *wut;

	i = 1;
	while (argc - i > 0)
	{
		l = 1;
		if (ft_atoi(argv[argc - i]) == 0 && ft_strcmp(argv[argc - i], "0") != 0 &&
			ft_strcmp(argv[argc - i], "-v") != 0 && ft_strcmp(argv[argc - i], "-c") != 0 &&
			ft_strcmp(argv[argc - i], "-i") != 0)
			error();
		wut = ft_itoa(ft_atoi(argv[argc - i]));
		if (ft_strcmp(wut, argv[argc - i]) != 0 && ft_strcmp(argv[argc - i], "0") != 0 &&
			ft_strcmp(argv[argc - i], "-v") != 0 && ft_strcmp(argv[argc - i], "-c") != 0 &&
			ft_strcmp(argv[argc - i], "-i") != 0)
		{
			ft_memdel((void**)&wut);
			error();
		}
		ft_memdel((void**)&wut);
		while (argc - i - l > 0)
		{
			if (ft_atoi(argv[argc - i]) == ft_atoi(argv[argc - i - l]) && ft_strcmp(argv[argc - i], "-v") != 0 &&
				ft_strcmp(argv[argc - i], "-c") != 0 && ft_strcmp(argv[argc - i], "-i") != 0)
				error();
			l++;
		}
		i++;
	}
}

int 	look_for_flags(char **str, t_flags *f)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_strcmp(str[i], "-v") == 0)
		{
			f->flag_v = 1;
			count++;
		}
		if (ft_strcmp(str[i], "-c") == 0)
		{
			count++;
			f->flag_color = 1;
		}
		if (ft_strcmp(str[i], "-i") == 0)
		{
			count++;
			f->flag_count = 1;
		}
		i++;
	}
	return (count);
}

int 	len_of_arrays(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	check_for_error(char *str)
{
	char *wut;

	wut = ft_itoa(ft_atoi(str));
	if (ft_strcmp(wut, str) != 0 && ft_strcmp(str, "-v") != 0 &&
		ft_strcmp(str, "-c") != 0 && ft_strcmp(str, "-i") != 0)
	{
		ft_memdel((void**)&wut);
		error ();
	}
	ft_memdel((void**)&wut);
}

void	clear_array(char **str)
{
	int i;

	i = len_of_arrays(str) - 1;
	while (i >= 0)
	{
		ft_memdel((void**)&str[i]);
		i--;
	}
	ft_memdel((void**)&str);
}

void	handle_one_arg(char **argv, t_stack *s, t_flags *f)
{
	char **ans;
	int i;
	int l;

	f = initialize_flags();
	ans = ft_strsplit(argv[1], ' ');
	i = len_of_arrays(ans) - 1;
	s = initialize(len_of_arrays(ans) - look_for_flags(ans, f) + 1);
	while (i >= 0)
	{
		check_for_error(ans[i]);
		l = 1;
		while (i - l >= 0)
		{
			if (ft_atoi(ans[i]) == ft_atoi(ans[i - l]) && ft_strcmp(ans[i], "-v") != 0 && ft_strcmp(ans[i], "-c") != 0 && ft_strcmp(ans[i], "-i") != 0)
				error();
			l++;
		}
		if (ft_strcmp(ans[i], "-v") != 0 && ft_strcmp(ans[i], "-c") != 0 && ft_strcmp(ans[i], "-i") != 0)
			push_a(s, ft_atoi(ans[i]));
		i--;
	}
	clear_array(ans);
	if (s->top_a < 10)
		lets_sort(s, f);
	else
		main_sort(s, f);
	destroy_stack(s);
	ft_memdel((void**)&f);
}

void	handle_file(int fd, t_stack *s, t_flags *f)
{
	char *line;
	char **ans;
	int i;
	int l;
	char *wut;

	if (!get_next_line(fd, &line))
		error();
	ans = ft_strsplit(line, ' ');
	s = initialize(len_of_arrays(ans) + 1);
	f = initialize_flags();
	i = len_of_arrays(ans) - 1;
	while (i >= 0)
	{
		wut = ft_itoa(ft_atoi(ans[i]));
		if (ft_strcmp(wut, ans[i]) != 0)
		{
			ft_memdel((void**)&wut);
			error();
		}
		ft_memdel((void**)&wut);
		l = 1;
		while (i - l >= 0)
		{
			if (ft_atoi(ans[i]) == ft_atoi(ans[i - l]))
				error();
			l++;
		}
		push_a(s, ft_atoi(ans[i]));
		i--;
	}
	if (s->top_a < 10)
		lets_sort(s, f);
	else
		main_sort(s, f);
	destroy_stack(s);
	ft_memdel((void**)&f);
	exit(0);
}

int 	main(int argc, char **argv)
{
	t_stack		*stack;
	t_flags		*flags;
	int			i;
	int 		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
		handle_file(fd, stack, flags);
	else if (argc == 2)
		handle_one_arg(argv, stack, flags);
	else
	{
		look_for_errors(argc, argv);
		i = 1;
		stack = initialize(argc);
		flags = initialize_flags();
		while (argc - i > 0)
		{
			if (ft_strcmp(argv[argc - i], "-v") == 0)
				flags->flag_v = 1;
			else if (ft_strcmp(argv[argc - i], "-c") == 0)
				flags->flag_color = 1;
			else if (ft_strcmp(argv[argc - i], "-i") == 0)
				flags->flag_count = 1;
			else
				push_a(stack, ft_atoi(argv[argc - i]));
			i++;
		}
		if (argc < 10)
			lets_sort(stack, flags);
		else
			main_sort(stack, flags);
		destroy_stack(stack);
		ft_memdel((void**)&flags); 
	}
}
