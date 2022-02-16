/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:55 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:21:55 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	rotate_for_score(t_env *env, int acc)
{
	int				len;

	len = ft_lstsize(env->b_head);
	if (len / 2 >= acc)
		while (acc--)
			ft_rarb(&(env->b_head), 2);
	else
	{
		acc = len - acc;
		while (acc--)
			ft_rrarrb(&(env->b_head), 2);
	}
}

void	get_min_score(t_env *env)
{
	int		min_score;
	t_list	*b_head;
	int		acc;
	int		count;

	b_head = env->b_head;
	min_score = INT_MAX;
	acc = 0;
	count = 0;
	while (b_head)
	{
		if (b_head->score < min_score)
		{
			min_score = b_head->score;
			acc = count;
		}
		b_head = b_head->next;
		++count;
	}
	rotate_for_score(env, acc);
}

int	ab_score(t_list *a_head, int val)
{
	t_list			*a_head_next;
	t_list			*last;
	int				acc;
	int				len;

	last = ft_lstlast(a_head);
	acc = 0;
	len = ft_lstsize(a_head);
	a_head_next = a_head->next;
	if (last->value < val && val < a_head->value)
		return (acc);
	while (a_head->next)
	{
		++acc;
		if (a_head->value < val && val < a_head_next->value)
			break ;
		a_head = a_head->next;
		a_head_next = a_head->next;
	}
	if (last->value > val && val > a_head->value)
		++acc;
	if (len / 2 >= acc)
		return (acc);
	else
		return (len - acc);
}

void	get_b_score(t_env *env)
{
	t_list	*b_score_for_b;
	int		acc;
	int		len;

	b_score_for_b = env->b_head;
	acc = 0;
	len = ft_lstsize(b_score_for_b);
	while (b_score_for_b)
	{
		++acc;
		if (len / 2 >= acc)
			b_score_for_b->score = acc;
		else
			b_score_for_b->score = len - acc;
		b_score_for_b->score += ab_score(env->a_head, b_score_for_b->value);
		b_score_for_b = b_score_for_b->next;
	}
}

void	ft_align(t_env *env, int min)
{
	t_list	*dup_a_head;
	int		acc;
	int		len;

	acc = 0;
	dup_a_head = env->a_head;
	len = ft_lstsize(dup_a_head);
	while (dup_a_head->value != min)
	{
		acc++;
		dup_a_head = dup_a_head->next;
	}
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
