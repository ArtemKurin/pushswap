
#include "./includes/push_swap.h"
#include <stdio.h>
void	ft_papb(t_list **a_head, t_list **b_head)
{
	t_list	*b_next;
	// if (!b_head)

	//printf("a_head_val: %d\n", (*a_head)->value);
	b_next = (*b_head)->next;
	ft_lstadd_front(a_head, *b_head);
	//printf("ququ");
	*b_head = b_next;
	//printf("a_head_val: %d\n", (*a_head)->value);
}

void	ft_sasb(t_list **a_head)
{
	t_list	*prev;

	prev = (*a_head)->next;
	(*a_head)->next = prev->next;
	ft_lstadd_front(a_head, prev);
}

void	ft_rarb(t_list **a_head)
{
	t_list	*new_last;
	t_list	*new_first;


	//printf("val: %d\n", (*a_head)->value);
	new_last = *a_head;
	new_first = (*a_head)->next;
	ft_lstadd_back(a_head, new_last);
	*a_head = new_first;
	new_last->next = NULL;
}

void	ft_rrarrb(t_list **head)
{

	int		size;

	size = ft_lstsize(*head);
	while (--size)
		ft_rarb(head);
}