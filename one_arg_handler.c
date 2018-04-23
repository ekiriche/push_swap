/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:15:20 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:15:32 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_the_norminette(char **ans, t_stack *s)
{
	int i;
	int l;

	i = len_of_arrays(ans) - 1;
	while (i >= 0)
	{
		check_for_error(ans[i]);
		l = 1;
		while (i - l >= 0)
		{
			if (ft_atoi(ans[i]) == ft_atoi(ans[i - l]) &&
				ft_strcmp(ans[i], "-v") != 0 &&
				ft_strcmp(ans[i], "-c") != 0 &&
				ft_strcmp(ans[i], "-i") != 0)
				error();
			l++;
		}
		if (ft_strcmp(ans[i], "-v") != 0 &&
			ft_strcmp(ans[i], "-c") != 0 &&
			ft_strcmp(ans[i], "-i") != 0)
			push_a(s, ft_atoi(ans[i]));
		i--;
	}
}

void	handle_one_arg(char **argv, t_stack *s, t_flags *f)
{
	char **ans;

	f = initialize_flags();
	ans = ft_strsplit(argv[1], ' ');
	s = initialize(len_of_arrays(ans) - look_for_flags(ans, f) + 1);
	for_the_norminette(ans, s);
	clear_array(ans);
	if (s->top_a < 10)
		lets_sort(s, f);
	else
		main_sort(s, f);
	destroy_stack(s);
	ft_memdel((void**)&f);
}
