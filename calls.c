/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:25 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/30 21:47:32 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	*ft_myfree(char **argv, t_env *env, int *array)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (env)
	{
		if (env->a_head)
			ft_lstclear(&(env->a_head));
		free(env);
	}
	if (array)
		free(array);
	return (NULL);
}

int	*check_all(int argc, char **argv, t_env **env)
{
	int		acc;
	int		*array;
	int		i;

	acc = 1;
	if (!check_param(argc, argv))
		return (ft_myfree(argv, *env, NULL));
	if (!check_atoi(argv, argc))
		return (ft_myfree(argv, *env, NULL));
	array = malloc(sizeof(int) * argc - 1);
	i = 0;
	while (acc < argc)
		array[i++] = ft_atoi(argv[acc++]);
	if (!check_duplicate(array, argc - 1))
		return (ft_myfree(argv, *env, array));
	*env = ft_lstnew_env();
	if (!*env)
		return (ft_myfree(argv, NULL, array));
	return (array);
}

int	ft_packing(int argc, char **argv, t_env *env, int flagcheck)
{
	t_list	*current;
	int		acc;

	acc = 1;
	while (acc < argc)
	{
		current = ft_lstnew(ft_atoi(argv[acc++]));
		if (!current)
			return (0);
		ft_lstadd_back(&env->a_head, current);
	}
	if (argc <= 6 && !flagcheck)
	{
		if (ft_lstsize(env->a_head) != 1 && \
		checklst_sort(env->a_head, get_min_for_small(env->a_head)))
		{
			ft_align(env, get_min_for_small(env->a_head));
			ft_myfree(argv, env, NULL);
			return (0);
		}
		small_sort(env);
		ft_myfree(argv, env, NULL);
		return (0);
	}
	return (1);
}

int	ft_start_sort(t_env *env, int *array, int argc, char **argv)
{
	int		mid;
	int		min;
	int		max;

	mid = ft_sort(array, argc - 1, &min, &max);
	if (!ft_packing(argc, argv, env, 0))
	{
		free(array);
		return (1);
	}
	if (argc > 6 && checklst_sort(env->a_head, min))
	{
		ft_align(env, min);
		ft_myfree(argv, env, array);
		return (0);
	}
	if (--argc == 500)
		return (sort500(env, array, argc, argv));
	my_sort(env, mid, min, max);
	rotate(env, get_min_index(env, min));
	ft_myfree(argv, env, array);
	return (1);
}

char	**get_all_args(int *argc, char **argv)
{
	char	**args;
	char	**res;
	int		acc;
	int		i;

	acc = 0;
	args = ft_split(*(argv + 1), ' ');
	while (args[acc])
		acc++;
	res = (char **)malloc(sizeof(char *) * (acc + (*argc)));
	if (!res)
		return (NULL);
	res[0] = ft_strdup(*argv);
	acc = -1;
	while (args[++acc])
		res[1 + acc] = ft_strdup(args[acc]);
	i = 2;
	while (i <= (*argc))
		res[1 + acc++] = ft_strdup(argv[i++]);
	*argc = acc;
	ft_myfree(args, NULL, NULL);
	return (res);
}
