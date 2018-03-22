/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/03/22 16:52:02 by ekiriche         ###   ########.fr       */
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
		ft_printf("%s\n", "nope");
	else
	{
		tmp = s->stack_b[s->top_b - 1];
		s->stack_b[s->top_b - 1] = s->stack_b[s->top_b - 2];
		s->stack_b[s->top_b - 2] = tmp;
	}
}

void		destroy_stack(t_stack *stack)
{
	ft_memdel((void**)&stack->stack_a);
	ft_memdel((void**)&stack->stack_b);
	ft_memdel((void**)&stack);
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
	sa(stack);
	i = 0;
	while (stack->top_a != 0)
	{
		ft_printf("%i\n", pop_a(stack));
		i++;
	}
	destroy_stack(stack);
	exit (0);
}
