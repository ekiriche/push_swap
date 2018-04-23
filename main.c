/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 14:00:10 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int argc, char **argv)
{
	t_stack		*stack;
	t_flags		*flags;
	int			i;
	int 		fd;

	stack = NULL;
	flags = NULL;
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
