/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:59:00 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 13:59:09 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# define TRY(x, y) (!(ft_strcmp(x, y)) ? 0 : 1)

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef	struct		s_lst
{
	char			c;
	int				num;
	int				bl;
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_validator(int num, char **arg);
t_lst				*ft_set_stack(int num, long *arg);
void				ft_ladd(t_lst **head, t_lst *new);
t_lst				*ft_lnew(int num);
void				ft_ldel(t_lst **head);
void				ft_swap(t_lst **head, char c);
void				ft_sswap(t_lst **a, t_lst **b, char c);
void				ft_pushes(t_lst **src, t_lst **dst, char c);
void				ft_error(void);
void				ft_rotates(t_lst **head, char c);
void				ft_rrotates(t_lst **a, t_lst **b, char c);
void				ft_revr(t_lst **head, char c);
void				ft_rrevr(t_lst **a, t_lst **b, char c);
void				ft_sort(t_lst **a, t_lst **b);
int					ft_count_mid(t_lst **a, int *count);
int					ft_sorted(t_lst *a);
int					ft_find_num(t_lst *a, int mid);
int					ft_find_num(t_lst *a, int mid);
int					ft_find_bl(t_lst *a, int ord);
void				ft_marker(t_lst **b, int m);
int					ft_lstlen(t_lst *a);
int					ft_brut_sort(t_lst **a, int i);
void				ft_sort_tree(t_lst **a, t_lst **b);
int					ft_order_three(t_lst *a);
void				ft_main_sort(t_lst **a, t_lst **b);
void				ft_free(t_lst **a, t_lst **b);
int					ft_dev_b(t_lst **a, t_lst **b, int mid, int temp);
int					ft_dev_a(t_lst **a, t_lst **b, int mid, int temp);
int					ft_sorted_stack(t_lst *a);
void				ft_bubble_sort(t_lst **a, t_lst **b);
void				ft_show_stack(t_lst *a);
void				ft_descending(t_lst **a, t_lst **b);

#endif
