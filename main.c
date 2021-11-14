#include "./includes/push_swap.h"
#include <stdio.h>
// обработка ошибок на макс и мин инт
// разнести main
// подключить check и small_sort
// добавить вывод сделанных команд если нужно

t_env	*ft_lstnew_env()
{
	t_env	*beginPointer;

	beginPointer = (t_env *)malloc(sizeof(t_env));
	if (beginPointer == (NULL))
		return (beginPointer);
	return (beginPointer);
}

void	ft_swap (int *i, int *a, int *last_swap, int index)
{
	int	c;

	c = *i;
	*i = *a;
	*a = c;
	*last_swap = index;
}

int	ft_sort(int *array, int length, int *min, int *max)
{
	int	left;
	int	right;
	int	last_swap;
	int	i;
	int	j;

	left = 0;
	right = length - 1;
	while (left < right)
	{
		i = left;
		last_swap = 0;
		while (i < right)
		{
			if (array[i] > array[i + 1])
				ft_swap(&array[i], &array[i + 1], &last_swap, i);
			i++;
		}
		right = last_swap;
		j = right;
		while (j > left)
		{
			if (array[j] < array[j - 1])
				ft_swap(&array[j], &array[j - 1], &last_swap, j);
			j--;
		}
		left = last_swap;
	}
	*min = array[0];
	*max = array[length - 1];
	return (array[length / 2]);
}

int main(int argc, char **argv)
{
	int		acc;
	t_env	*env;
	t_list	*current;
	int		*array;
	int		i;
	int		mid;
	int		min;
	int		max;

	acc = 1;
	env = ft_lstnew_env();
	if (!env)
		return (0);	
	array = malloc(sizeof(int) * argc - 1);
	i = 0;
	while (acc < argc)
	{
		array[i++] = ft_atoi(argv[acc++]);
	}
	i = 0;
	mid = ft_sort(array, argc - 1, &min, &max);
	if (!env)
		return (0);
	acc = 1;
	while (acc < argc)
	{
		current = ft_lstnew(ft_atoi(argv[acc++]));
		if (!current)
			return (0);
		ft_lstadd_back(&env->a_head, current);
	}
	my_sort(env, mid, min, max);
	return (1);
}


// while (env->a_head)
// 	{
// 		printf("a: %d\n", env->a_head->value);
// 		env->a_head = env->a_head->next;
// 		//ft_lstdelone(env->a_head->prev);
// 	}
// 	printf("\n");
// 	while (env->b_head)
// 	{
// 		printf("b: %d\n", env->b_head->value);
// 		env->b_head = env->b_head->next;
// 		//ft_lstdelone(env->b_head->prev);
// 	}