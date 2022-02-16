/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:24:47 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:24:47 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	move_to_b(t_env *env, int mid, int min, int max)
{
	int		len;

	len = ft_lstsize(env->a_head);
	while (len--)
	{
		if (env->a_head->value != min && env->a_head->value != max)
			ft_papb(&(env->b_head), &(env->a_head), 2);
		if ((env->a_head->value == min || env->a_head->value == max) \
		&& ft_lstsize(env->a_head) > 2)
			ft_rarb(&(env->a_head), 1);
		else if (env->b_head && env->b_head->value > mid \
		&& ft_lstsize(env->b_head) > 1)
			ft_rarb(&(env->b_head), 2);
	}
}

void	rotate(t_env *env, int acc)
{
	int				len;

	len = ft_lstsize(env->a_head);
	if (len / 2 >= acc)
		while (acc--)
			ft_rarb(&(env->a_head), 1);
	else
	{
		acc = len - acc;
		while (acc--)
			ft_rrarrb(&(env->a_head), 1);
	}
}

void	a_rotate(t_env *env, int val)
{
	t_list			*a_head_next;
	t_list			*last;
	int				acc;
	t_list			*head;

	last = ft_lstlast(env->a_head);
	acc = 0;
	head = env->a_head;
	a_head_next = env->a_head->next;
	if (last->value < val && val < head->value)
		return ;
	while (head->next)
	{
		++acc;
		if (head->value < val && val < a_head_next->value)
		{
			last = head;
			break ;
		}
		head = head->next;
		a_head_next = head->next;
	}
	if (last->value > val && val > head->value)
		++acc;
	rotate(env, acc);
}

void	move_to_a(t_env *env)
{
	int	lenB;

	lenB = ft_lstsize(env->b_head);
	while (lenB--)
	{
		get_b_score(env);
		get_min_score(env);
		a_rotate(env, env->b_head->value);
		ft_papb(&(env->a_head), &(env->b_head), 1);
	}
}

void	my_sort(t_env *env, int mid, int min, int max)
{
	move_to_b(env, mid, min, max);
	move_to_a(env);
}
