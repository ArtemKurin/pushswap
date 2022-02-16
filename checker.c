/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:54:53 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/30 21:32:21 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

void	ft_checker(char *command, t_env *env)
{
	if (ft_strcmp(command, "pa\n"))
		ft_papb(&(env->a_head), &(env->b_head), 0);
	else if (ft_strcmp(command, "pb\n"))
		ft_papb(&(env->b_head), &(env->a_head), 0);
	else if (ft_strcmp(command, "sa\n"))
		ft_sasb(&(env->a_head), 0);
	else if (ft_strcmp(command, "sb\n"))
		ft_sasb(&(env->b_head), 0);
	else if (ft_strcmp(command, "ra\n"))
		ft_rarb(&(env->a_head), 0);
	else if (ft_strcmp(command, "rb\n"))
		ft_rarb(&(env->b_head), 0);
	else if (ft_strcmp(command, "rra\n"))
		ft_rrarrb(&(env->a_head), 0);
	else if (ft_strcmp(command, "rrb\n"))
		ft_rrarrb(&(env->b_head), 0);
	else if (ft_strcmp(command, "rrr\n"))
		ft_rrr(env, 0);
	else if (ft_strcmp(command, "rr\n"))
		ft_rr(env, 0);
	else if (ft_strcmp(command, "ss\n"))
		ft_ss(env, 0);
	else
		ft_error();
}

void	do_command(t_env *env)
{
	char	*command;

	command = get_next_line(0);
	while (command && command[0] != '\n')
	{
		ft_checker(command, env);
		free(command);
		command = get_next_line(0);
	}
	if (command)
		free(command);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		*array;
	int		size;

	env = NULL;
	if (argc > 1)
		argv = get_all_args(&argc, argv);
	else
		exit(1);
	array = check_all(argc, argv, &env);
	if (!array)
		ft_error();
	ft_packing(argc, argv, env, 1);
	size = ft_lstsize(env->a_head);
	do_command(env);
	if (size == 1 || (checklst_sort(env->a_head, env->a_head->value) \
	&& size == ft_lstsize(env->a_head)))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_myfree(argv, env, array);
	return (1);
}
