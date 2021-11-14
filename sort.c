#include "./includes/push_swap.h"
#include <stdio.h>
void	make_midle_first(t_env *env, int mid)
{
	t_list	*duplicate;
	int		acc_rotate;
	int		len;

	duplicate = env->a_head;
	len = ft_lstsize(duplicate);
	acc_rotate = 0;
	while (duplicate->value != mid)
	{
		acc_rotate++;
		duplicate = duplicate->next;
	}
	if (len / 2 >= acc_rotate)
		while (env->a_head->value != mid)
			ft_rarb(&(env->a_head));
	else
		while (env->a_head->value != mid)
			ft_rrarrb(&(env->a_head));
}

void	move_to_b(t_env *env, int mid, int min, int max)
{
	int		len;

	len = ft_lstsize(env->a_head);
	while (--len)
	{
		if (env->a_head->value != min && env->a_head->value != max)
			ft_papb(&(env->b_head), &(env->a_head));
		if (env->a_head->value == min || env->a_head->value == max)
			ft_rarb(&(env->a_head));
		if (env->b_head->value > mid)
			ft_rarb(&(env->b_head));
	}
}

void	rotate(t_env *env, int acc)
{
	int				len;

	len = ft_lstsize(env->a_head);
	if (len / 2 >= acc)
		while (acc--)
			ft_rarb(&(env->a_head));
	else
	{
		acc = len - acc;
		while (acc--)
			ft_rrarrb(&(env->a_head));
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
			break;
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
		ft_papb(&(env->a_head), &(env->b_head));
	}
}

void	my_sort(t_env *env, int mid, int min, int max)
{
	make_midle_first(env, mid);
	move_to_b(env, mid, min, max);
	//env->a_head->next->next = NULL;
	move_to_a(env);
	// printf("lenB: %d\n", ft_lstsize(env->b_head));
	// printf("lenA: %d\n", ft_lstsize(env->a_head));
}