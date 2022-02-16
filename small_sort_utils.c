/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:24:43 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:24:44 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_min_for_small(t_list *head)
{
	int	size;
	int	min;

	size = ft_lstsize(head);
	min = INT_MAX;
	while (size--)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}

int	get_max_for_small(t_list *head)
{
	int	size;
	int	max;

	max = INT_MIN;
	size = ft_lstsize(head);
	while (size--)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}

int	get_mid_for_small(t_list *head, int min, int max)
{
	int	size;
	int	mid;

	size = ft_lstsize(head);
	while (size--)
	{
		if (head->value != max && head->value != min)
			mid = head->value;
		head = head->next;
	}
	return (mid);
}

void	ft_get_acc(t_env *env, int min)
{
	int		acc;
	t_list	*a_head;

	acc = 0;
	a_head = env->a_head;
	while (a_head->value != min)
	{
		acc++;
		a_head = a_head->next;
	}
	rotate(env, acc);
}
