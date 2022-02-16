/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:31:14 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/27 18:27:28 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_rr(t_env *env, int printflag)
{
	if (printflag == 1)
		write(1, "rr\n", 3);
	ft_rarb(&(env->a_head), 0);
	ft_rarb(&(env->b_head), 0);
}

void	ft_ss(t_env *env, int printflag)
{
	if (printflag == 1)
		write(1, "ss\n", 3);
	ft_sasb(&(env->a_head), 0);
	ft_sasb(&(env->b_head), 0);
}
