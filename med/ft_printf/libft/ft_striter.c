/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:22:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/03 10:14:48 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(&s[i]);
			i++;
		}
	}
}