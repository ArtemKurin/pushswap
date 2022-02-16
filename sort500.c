/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:53:33 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/30 21:36:00 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	rotate_for_score_a(t_env *env, int acc)
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

void	get_min_score_a(t_env *env, int index, int min, int max)
{
	int		min_score;
	t_list	*a_head;
	int		acc;
	int		count;

	a_head = env->a_head;
	min_score = INT_MAX;
	acc = 0;
	count = 0;
	while (a_head)
	{
		if (a_head->score < min_score && a_head->index == index \
		&& a_head->value != min && a_head->value != max)
		{
			min_score = a_head->score;
			acc = count;
		}
		a_head = a_head->next;
		++count;
	}
	rotate_for_score_a(env, acc);
}

void	get_a_score(t_env *env)
{
	t_list	*a_head;
	int		i;

	a_head = env->a_head;
	i = 0;
	while (a_head)
	{
		a_head->score = i++;
		a_head = a_head->next;
	}
}

void	move_to_b2(t_env *env, int min, int max, int argc)
{
	int		index;
	int		size_chunk;
	int		kef;

	index = 5;
	kef = 4;
	while (index)
	{
		size_chunk = argc / 4;
		if (index == 1)
			size_chunk = (argc / 4) - 2;
		while (size_chunk--)
		{
			get_a_score(env);
			get_min_score_a(env, index, min, max);
			if (env->a_head->value != min && env->a_head->value != max)
				ft_papb(&(env->b_head), &(env->a_head), 2);
		}
		index--;
	}
}

int	sort500(t_env *env, int *array, int argc, char **argv)
{
	t_list	*a_head;
	int		i;
	int		index;
	int		kef;

	i = -1;
	index = 1;
	kef = 4;
	while (++i < argc)
	{
		a_head = env->a_head;
		if (i % (argc / kef) == 0)
			index++;
		while (a_head->value != array[i])
			a_head = a_head->next;
		a_head->index = index;
	}
	move_to_b2(env, array[0], array[argc - 1], argc);
	move_to_a(env);
	rotate(env, get_min_index(env, array[0]));
	ft_myfree(argv, env, array);
	return (1);
}
