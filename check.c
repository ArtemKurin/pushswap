#include "./includes/push_swap.h"

int	check_param(int argc, char **argv)
{
	int	acc;
	int	i;

	acc = 1;
	if (argc < 2)
		return (0);
	while (acc < argv)
	{
		i = 0;
		while (argv[acc][i])
			if (!ft_isdigit(argv[acc][i++]))
				return (0);
	}
	return (1);
}

int	check_duplicate(int *array, int len)
{
	int	i;

	i = 0;
	while (++i < len)
		if (array[i - 1] == array[i])
			return (0);
	return (1);
}

int	checklst_sort(t_list *head, int min)
{
	t_list	next_head;

	next_head = head->next;
	while (next_head->value != min && head->value != min)
	{
		if (head->value > next_head->value)
			return (0);
		head = head->next;
		next_head = head->next;
	}
	while (next_head)
	{
		if (head->value > next_head->value)
			return (0);
		head = head->next;
		next_head = head->next;
	}
	return (1);
}

void	ft_align(t_env *env, int min)
{
	t_list	*dup_a_head;
	int		acc;
	int		len;
	
	acc = 0;
	len = ft_lstsize(dup_a_head);
	while (dup_a_head->value != min)
	{
		acc++;
		dup_a_head = dup_a_head->next;
	}
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

int	check_atoi(char **str_num, int argc)
{
	int	num;
	int	len_num;

	while (--argc)
	{
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
		if (ft_strlen(str_num[argc]) != len_num)
			return (0);
	}
	return (1);
}