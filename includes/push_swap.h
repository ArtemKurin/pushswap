#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

// typedef struct		s_list
// {
// 	int				value;
// 	int				score;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }	t_list;

typedef struct		s_env
{
	t_list	*a_head;
	t_list	*b_head;
}	t_env;

void	ft_papb(t_list **in, t_list **out);
void	ft_sasb(t_list **a_head);
void	ft_rarb(t_list **a_head);
void	ft_rrarrb(t_list **head);
void	make_midle_first(t_env *env, int mid);
void	move_to_b(t_env *env, int mid, int min, int max);
void	my_sort(t_env *env, int mid, int min, int max);
void	a_rotate(t_env *env, int val);
void	move_to_a(t_env *env);
int		ab_score(t_list *a_head, int val);
void	get_b_score(t_env *env);
void	get_min_score(t_env *env);
void	a_rotate(t_env *env, int val);

#endif