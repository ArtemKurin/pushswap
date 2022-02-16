/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:43 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/30 19:47:31 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	int		*array;
	char	**nums;

	if (argc > 1)
	{
		env = NULL;
		nums = get_all_args(&argc, argv);
		array = check_all(argc, nums, &env);
		if (!array)
			ft_error();
		return (ft_start_sort(env, array, argc, nums));
	}
	return (1);
}
