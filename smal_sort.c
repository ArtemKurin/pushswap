#include "./includes/push_swap.h"

void	pb_min(t_env *env, int min)
{
	int		acc;
	t_list	*a_head;

	acc= 0;
	a_head = env->a_head;
	while (a_head->value != min)
	{
		acc++;
		a_head = a_head->next
	}
	rotate(env, acc);
	ft_papb(&(env->b_head), &(env->a_head));
}

void	a_sort(t_env *env)
{
	if (env->a_head->value > env->a_head->next->value && env->a_head->value > env->a_head->next->next->value)
		ft_rarb(&(env->a_head));
	if (env->a_head->value > env->a_head->next->value && env->a_head->value < env->a_head->next->next->value)
		ft_sasb(&(env->a_head));
	if (env->a_head->next->value > env->a_head->next->next->value && env->a_head->value < env->a_head->next->value)
		ft_rrarrb(&(env->a_head));
	if (env->a_head->value > env->a_head->next->value && env->a_head->value < env->a_head->next->next->value)
		ft_sasb(&(env->a_head));
}

void	small_sort(t_env *env, int min)
{
	t_list	*a_head;

	pb_min(env, min);
	min = 2000000;// INT_MAX
	a_head = env->a_head;
	while (a_head)
	{
		if (a_head->value < min)
			min = a_head->value;
		a_head = a_head->next;
	}
	pb_min(env, min);
	a_sort(env);
	ft_papb(&(env->a_head), &(env->b_head));
	ft_papb(&(env->a_head), &(env->b_head));
}