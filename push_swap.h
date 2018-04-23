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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	int				a_max;
	int				a_max_idx;
}					t_stack;

typedef struct 		s_flags
{
	int 			flag_v;
	int				flag_color;
	int				flag_count;
}					t_flags;

void				main_sort(t_stack *s, t_flags *f);
void				lets_sort(t_stack *s, t_flags *f);
void				push_to_a(t_stack *s, int *count, t_flags *f);
void				sort_a(t_stack *s, int *count, t_flags *f);
void				push_to_b(t_stack *s, int idx, int *count, t_flags *f);
int		find_median_a(t_stack *s);
int 	len_of_arrays(char **str);
int 	look_for_flags(char **str, t_flags *f);
void	handle_one_arg(char **argv, t_stack *s, t_flags *f);
void	handle_file(int fd, t_stack *s, t_flags *f);
void	print_s(t_stack *s, char *oper, t_flags *f);
void	check_for_error(char *str);
void	look_for_errors(int argc, char **argv);
void	error();
void	find_max(t_stack *s);
void	find_min(t_stack *s);
int		smallest_side(t_stack *s);
int		if_first_smallest(t_stack *s);
int		if_sorted(t_stack *s);
void	clear_array(char **str);
t_flags	*initialize_flags();
void		destroy_stack(t_stack *stack);
t_stack		*initialize(int size);
void		sb(t_stack *s);
void		pb(t_stack *s);
void		rb(t_stack *s);
void		rrb(t_stack *s);
void		sa(t_stack *s);
void		pa(t_stack *s);
void		ra(t_stack *s);
void		rra(t_stack *s);
void		ss(t_stack *s);
void		rr(t_stack *s);
void		rrr(t_stack *s);
void	push_b(t_stack *stack, int data);
int		pop_b(t_stack *stack);
void	push_a(t_stack *stack, int data);
int		pop_a(t_stack *stack);
void	actualy_sort(t_stack *s);
int 	if_empty(int *str);
void	handle_one_param_check(t_stack *s, char *str);

#endif
