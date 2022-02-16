/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smal_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:58 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:21:58 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort3el(t_env *env, int min, int max, int mid)
{
	if (env->a_head->value == min && env->a_head->next->value != mid)
		ft_sasb(&(env->a_head), 1);
	else if (env->a_head->value == max && env->a_head->next->value != min)
		ft_sasb(&(env->a_head), 1);
	else if (env->a_head->value == mid && env->a_head->next->value != max)
		ft_sasb(&(env->a_head), 1);
}

void	sort4(t_env *env, int min, int max)
{
	if (env->b_head->value > max)
	{
		if (env->a_head->next->value == max)
			ft_rrarrb(&(env->a_head), 1);
		if (env->a_head->value == max)
			ft_rarb(&(env->a_head), 1);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
	else if (env->b_head->value < min)
	{
		if (env->a_head->next->value == min)
			ft_rarb(&(env->a_head), 1);
		if (env->a_head->next->next->value == min)
			ft_rrarrb(&(env->a_head), 1);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
	else
	{
		a_rotate(env, env->b_head->value);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
}

void	sort5(t_env *env)
{
	int	min;
	int	max;

	min = get_min_for_small(env->a_head);
	max = get_max_for_small(env->a_head);
	if (env->b_head && env->b_head->value < min)
	{
		ft_get_acc(env, min);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
	else if (env->b_head && env->b_head->value > max)
	{
		ft_get_acc(env, min);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
	else if (env->b_head)
	{
		a_rotate(env, env->b_head->value);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
}

void	small_sort(t_env *env)
{
	int	min;
	int	max;
	int	mid;

	if (ft_lstsize(env->a_head) == 1)
		return ;
	if (ft_lstsize(env->a_head) == 5)
	{
		ft_papb(&(env->b_head), &(env->a_head), 2);
		ft_papb(&(env->b_head), &(env->a_head), 2);
	}
	if (ft_lstsize(env->a_head) == 4)
		ft_papb(&(env->b_head), &(env->a_head), 2);
	min = get_min_for_small(env->a_head);
	max = get_max_for_small(env->a_head);
	mid = get_mid_for_small(env->a_head, min, max);
	sort3el(env, min, max, mid);
	if (env->b_head)
		sort4(env, min, max);
	if (env->b_head)
		sort5(env);
	min = get_min_for_small(env->a_head);
	ft_align(env, min);
}
