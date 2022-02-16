/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:25:09 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 13:25:09 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// # include "../get_next_line.h"
# include <stdlib.h>
# include "./libft/libft.h"
typedef struct s_env
{
	t_list	*a_head;
	t_list	*b_head;
}	t_env;

void	get_a_score(t_env *env);
int		*ft_myfree(char **argv, t_env *env, int *array);
void	get_min_score_a(t_env *env, int index, int min, int max);
void	rotate_for_score_a(t_env *env, int acc);
void	ft_error(void);
int		sort500(t_env *env, int *array, int argc, char **argv);
char	**get_all_args(int *argc, char **argv);
void	ft_papb(t_list **in, t_list **out, int printflag);
void	ft_sasb(t_list **a_head, int printflag);
void	ft_rarb(t_list **a_head, int printflag);
void	ft_rrarrb(t_list **head, int printflag);
void	ft_rrr(t_env *env, int printflag);
void	ft_rr(t_env *env, int printflag);
void	ft_ss(t_env *env, int printflag);
void	make_midle_first(t_env *env, int mid);
void	move_to_b(t_env *env, int mid, int min, int max);
void	my_sort(t_env *env, int mid, int min, int max);
void	a_rotate(t_env *env, int val);
void	move_to_a(t_env *env);
int		ab_score(t_list *a_head, int val);
void	get_b_score(t_env *env);
void	get_min_score(t_env *env);
void	rotate(t_env *env, int acc);
int		check_param(int argc, char **argv);
int		check_duplicate(int *array, int len);
int		check_atoi(char **str_num, int argc);
int		checklst_sort(t_list *head, int min);
void	ft_align(t_env *env, int min);
void	small_sort(t_env *env);
int		get_min_for_small(t_list *head);
int		get_max_for_small(t_list *head);
int		get_mid_for_small(t_list *head, int min, int max);
void	ft_get_acc(t_env *env, int min);
int		*check_all(int argc, char **argv, t_env **env);
int		ft_packing(int argc, char **argv, t_env *env, int flagcheck);
int		ft_start_sort(t_env *env, int *array, int argc, char **argv);
t_env	*ft_lstnew_env(void);
int		ft_sort(int *array, int length, int *min, int *max);
int		get_min_index(t_env *env, int min);

#endif