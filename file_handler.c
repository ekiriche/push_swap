/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:15:02 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 17:11:17 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_from_file(char **ans, t_stack *s)
{
	int		i;
	int		l;
	char	*wut;

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
}

void	handle_file(int fd, t_stack *s, t_flags *f)
{
	char *line;
	char **ans;

	if (!get_next_line(fd, &line))
		error();
	ans = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	s = initialize(len_of_arrays(ans) + 1);
	f = initialize_flags();
	fill_stack_from_file(ans, s);
	if (s->top_a < 20)
		lets_sort(s, f);
	else
		main_sort(s, f);
	destroy_stack(s);
	clear_array(ans);
	ft_memdel((void**)&f);
}
