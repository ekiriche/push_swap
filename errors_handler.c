/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:08:01 by ekiriche          #+#    #+#             */
/*   Updated: 2018/04/23 13:08:10 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_for_intmax_intmin(int argc, int i, char **argv)
{
	char *wut;

	wut = ft_itoa(ft_atoi(argv[argc - i]));
	if (ft_strcmp(wut, argv[argc - i]) != 0 &&
		ft_strcmp(argv[argc - i], "0") != 0 &&
		ft_strcmp(argv[argc - i], "-v") != 0 &&
		ft_strcmp(argv[argc - i], "-c") != 0 &&
		ft_strcmp(argv[argc - i], "-i") != 0)
	{
		ft_memdel((void**)&wut);
		error();
	}
	ft_memdel((void**)&wut);
}

void	check_for_digit(char **argv, int argc, int i)
{
	if (ft_atoi(argv[argc - i]) == 0 &&
		ft_strcmp(argv[argc - i], "0") != 0 &&
		ft_strcmp(argv[argc - i], "-v") != 0 &&
		ft_strcmp(argv[argc - i], "-c") != 0 &&
		ft_strcmp(argv[argc - i], "-i") != 0)
		error();
}

void	look_for_errors(int argc, char **argv)
{
	int i;
	int l;

	i = 1;
	while (argc - i > 0)
	{
		l = 1;
		check_for_digit(argv, argc, i);
		check_for_intmax_intmin(argc, i, argv);
		while (argc - i - l > 0)
		{
			if (ft_atoi(argv[argc - i]) == ft_atoi(argv[argc - i - l]) &&
				ft_strcmp(argv[argc - i], "-v") != 0 &&
				ft_strcmp(argv[argc - i], "-c") != 0 &&
				ft_strcmp(argv[argc - i], "-i") != 0)
				error();
			l++;
		}
		i++;
	}
}

void	check_for_error(char *str)
{
	char *wut;

	wut = ft_itoa(ft_atoi(str));
	if (ft_strcmp(wut, str) != 0 && ft_strcmp(str, "-v") != 0 &&
		ft_strcmp(str, "-c") != 0 && ft_strcmp(str, "-i") != 0)
	{
		ft_memdel((void**)&wut);
		error();
	}
	ft_memdel((void**)&wut);
}
