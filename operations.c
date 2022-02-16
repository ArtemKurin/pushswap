/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:45 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:21:45 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
void	ft_papb(t_list **a_head, t_list **b_head, int printflag)
{
	t_list	*b_next;

	if (printflag == 1)
		write(1, "pa\n", 3);
	if (printflag == 2)
		write(1, "pb\n", 3);
	if (*b_head)
	{
		b_next = (*b_head)->next;
		ft_lstadd_front(a_head, *b_head);
		*b_head = b_next;
	}
}

void	ft_sasb(t_list **a_head, int printflag)
{
	t_list	*prev;

	if (printflag == 1)
		write(1, "sa\n", 3);
	if (printflag == 2)
		write(1, "sb\n", 3);
	if (*a_head && (*a_head)->next)
	{
		prev = (*a_head)->next;
		(*a_head)->next = prev->next;
		// ft_lstadd_front(a_head, prev);
		prev->next = *a_head;
		*a_head = prev;
	}
}

void	ft_rarb(t_list **a_head, int printflag)
{
	t_list	*new_last;
	t_list	*new_first;

	if (printflag == 1)
		write(1, "ra\n", 3);
	if (printflag == 2)
		write(1, "rb\n", 3);
	new_last = *a_head;
	if (new_last)
	{
		new_first = (*a_head)->next;
		if (new_first)
		{
			ft_lstadd_back(a_head, new_last);
			*a_head = new_first;
			new_last->next = NULL;
		}
	}
}

void	ft_rrarrb(t_list **head, int printflag)
{
	int		size;

	if (printflag == 1)
		write(1, "rra\n", 4);
	if (printflag == 2)
		write(1, "rrb\n", 4);
	size = ft_lstsize(*head);
	if (size > 1)
		while (--size)
			ft_rarb(head, 0);
}

void	ft_rrr(t_env *env, int printflag)
{
	if (printflag == 1)
		write(1, "rrr\n", 4);
	ft_rrarrb(&(env->a_head), 0);
	ft_rrarrb(&(env->b_head), 0);
}
