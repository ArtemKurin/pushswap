#include "./includes/push_swap.h"

void	get_min_score(t_env *env)
{
	int		min_score;
	t_list	*b_head;
	int		acc;
	int		len;
	int		count;

	b_head = env->b_head;
	min_score = 2000000000;//ili intMIN
	acc = 0;
	count = 0;
	len = ft_lstsize(b_head);
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
	if (len / 2 >= acc)
		while (acc--)
			ft_rarb(&(env->b_head));
	else
	{
		acc = len - acc;
		while (acc--)
			ft_rrarrb(&(env->b_head));
	}
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
			break;
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

	b_score_for_b = env->b_head;
	acc = 0;
	while (b_score_for_b)
	{
		b_score_for_b->score = ++acc;
		b_score_for_b->score += ab_score(env->a_head, b_score_for_b->value);
		b_score_for_b = b_score_for_b->next;
	}
}