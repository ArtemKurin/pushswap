/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:38 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:21:38 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_param(int argc, char **argv)
{
	int	acc;
	int	i;

	acc = 1;
	if (argc < 2)
		return (0);
	while (acc < argc)
	{
		i = -1;
		while (argv[acc][++i])
			if (!ft_isdigit(argv[acc][i]) && argv[acc][i] != '-')
				return (0);
		acc++;
	}
	return (1);
}

int	check_duplicate(int *array, int len)
{
	int	i;
	int	n;

	i = -1;
	while (++i < len)
	{
		n = -1;
		while (++n < i)
			if (array[i] == array[n])
				return (0);
	}
	return (1);
}

int	checklsts_helper(t_list *dup, t_list *head, int min)
{
	while (dup->value != min)
	{
		if (head->value > dup->value)
			return (0);
		head = head->next;
		dup = dup->next;
	}
	return (1);
}

int	checklst_sort(t_list *head, int min)
{
	t_list	*next_head;
	t_list	*dup;

	dup = head;
	while (head && head->value != min)
		head = head->next;
	next_head = head->next;
	while (next_head)
	{
		if (head->value > next_head->value)
			return (0);
		head = head->next;
		next_head = head->next;
	}
	if (head->value > dup->value && dup->value != min)
		return (0);
	else if (head->value > dup->value && dup->value == min)
		return (1);
	head = dup;
	dup = dup->next;
	return (checklsts_helper(dup, head, min));
}

int	check_atoi(char **str_num, int argc)
{
	int	num;
	int	len_num;

	while (--argc)
	{
		len_num = 0;
		num = ft_atoi(str_num[argc]);
		if (num == 0)
			len_num++;
		if (num < 0)
			len_num++;
		while (num)
		{
			++len_num;
			num /= 10;
		}
		if ((int)ft_strlen(str_num[argc]) != len_num)
			return (0);
	}
	return (1);
}
