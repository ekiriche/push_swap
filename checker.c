/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:40:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 19:26:35 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actualy_sort(t_stack *s)
{
	char *line;

	while (get_next_line(0, &line))
	{
		do_command(s, line);
		ft_memdel((void**)&line);
	}
	if (if_sorted(s) && s->top_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	this_world_is_doomed(t_stack *s, char **ans, int i)
{
	char	*wut;
	int		l;

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
		while (i - l > 1)
		{
			if (ft_atoi(ans[i]) == ft_atoi(ans[i - l]))
				error();
			l++;
		}
		push_a(s, ft_atoi(ans[i]));
		i--;
	}
}

void	handle_one_param_check(t_stack *s, char *str)
{
	char	**ans;
	int		i;

	ans = ft_strsplit(str, ' ');
	i = len_of_arrays(ans) - 1;
	s = initialize(i + 2);
	this_world_is_doomed(s, ans, i);
	actualy_sort(s);
	destroy_stack(s);
	clear_array(ans);
}

void	casual_check(t_stack *s, int argc, char **argv, int i)
{
	char	*wut;
	int		l;

	while (argc - i > 0)
	{
		wut = ft_itoa(ft_atoi(argv[argc - i]));
		if (ft_strcmp(wut, argv[argc - i]) != 0)
		{
			ft_memdel((void**)&wut);
			error();
		}
		ft_memdel((void**)&wut);
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
}

int		main(int argc, char **argv)
{
	t_stack	*s;
	int		i;

	i = 1;
	s = NULL;
	if (argc == 2)
		handle_one_param_check(s, argv[1]);
	else
	{
		s = initialize(argc);
		casual_check(s, argc, argv, i);
		actualy_sort(s);
		destroy_stack(s);
	}
}
