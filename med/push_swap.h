/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:53 by ekiriche          #+#    #+#             */
/*   Updated: 2018/03/26 18:19:51 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct		s_stack
{
	int				size;
	int				*stack_a;
	int				top_a;
	int				*stack_b;
	int				top_b;
	int				b_min;
	int				b_min_idx;
	int				b_max;
	int				b_max_idx;
	int				a_min;
	int				a_min_idx;
}					t_stack;

#endif
