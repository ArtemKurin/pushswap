/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:40 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:21:40 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_env	*ft_lstnew_env(void)
{
	t_env	*beginPointer;

	beginPointer = (t_env *)malloc(sizeof(t_env));
	beginPointer->a_head = NULL;
	beginPointer->b_head = NULL;
	if (beginPointer == (NULL))
		return (beginPointer);
	return (beginPointer);
}

void	ft_swap(int *i, int *a, int *last_swap, int index)
{
	int	c;

	c = *i;
	*i = *a;
	*a = c;
	*last_swap = index;
}

void	ft_sort_helper(int *array, int *left, int *right)
{
	int	last_swap;
	int	i;
	int	j;

	i = *left;
	last_swap = 0;
	while (i < *right)
	{
		if (array[i] > array[i + 1])
			ft_swap(&array[i], &array[i + 1], &last_swap, i);
		i++;
	}
	*right = last_swap;
	j = *right;
	while (j > *left)
	{
		if (array[j] < array[j - 1])
			ft_swap(&array[j], &array[j - 1], &last_swap, j);
		j--;
	}
	*left = last_swap;
}

int	ft_sort(int *array, int length, int *min, int *max)
{
	int	left;
	int	right;

	left = 0;
	right = length - 1;
	while (left < right)
		ft_sort_helper(array, &left, &right);
	*min = array[0];
	*max = array[length - 1];
	return (array[length / 2]);
}

int	get_min_index(t_env *env, int min)
{
	int		index;
	t_list	*a_head;

	index = 0;
	a_head = env->a_head;
	while (a_head)
	{
		if (a_head->value == min)
			return (index);
		a_head = a_head->next;
		index++;
	}
	return (0);
}
