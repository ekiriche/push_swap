/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_destroy_structs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:58:44 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 19:27:57 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		destroy_stack(t_stack *stack)
{
	ft_memdel((void**)&stack->stack_a);
	ft_memdel((void**)&stack->stack_b);
	ft_memdel((void**)&stack);
}

t_flags		*initialize_flags(void)
{
	t_flags *flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->flag_v = 0;
	flags->flag_color = 0;
	flags->flag_count = 0;
	return (flags);
}

void		clear_array(char **str)
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

int			if_empty(int *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (1);
	return (0);
}
