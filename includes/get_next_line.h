/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:37:25 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 14:22:45 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*read_file(char *residue, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int		my_str_copy(char *res, char *buff, int i);
char	*ft_strjoin(char *residue, char *buff);
char	*get_res_2(int i, char *line);
char	*get_result(char *line);
char	*get_residue(char *line);

#endif
