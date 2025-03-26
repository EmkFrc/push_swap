/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:11:43 by efranco           #+#    #+#             */
/*   Updated: 2025/01/31 17:11:43 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "Ft_printf/ft_printf.h"

typedef struct s_list {
	long			value;
	int				index;
	int				above_median;
	int				cost;
	int				cheapest;
	struct s_list	*target_node;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	sa(t_list **stack_a, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// Fonctions de rotate.c
void	ra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int flag);
void	rrb(t_list **stack_b, int flag);
void	rrr(t_list **stack_a, t_list **stack_b);

// Fonctions de algorithm.c
void	sorting_2(t_list **stack);
void	sorting_3(t_list **stack_a);
t_list	*is_smallest(t_list *stack_a);
void	search_close_target(t_list *stack_a, t_list *stack_b);
void	init_index(t_list *stack);
int		ft_lstsize(t_list *lst);
void	move_top(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	move_bottom(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	final_rotate_a(t_list **stack, t_list *cheapest);
void	final_rotate_b(t_list **stack, t_list *cheapest);
t_list	*find_cheapest(t_list *stack);
void	last_setting_stack_a(t_list **stack_a);
void	push_swap(t_list **stack_a, t_list **stack_b);
void	algo(t_list **stack_a, t_list **stack_b);
int		already_sort(t_list *stack);
// Fonctions de init.c
int		search_median(t_list *stack);
void	above_median(t_list *stack, int median);
void	init_cost(t_list *stack_a, t_list *stack_b);
void	init_cheapest(t_list *stack);
void	init_all(t_list **stack_a, t_list **stack_b);

// Fonctions de check_param.c
int		ft_word_size(const char *s, char c, int i);
int		ft_count_s(const char *s, char c);
char	*ft_strndup(const char *src, int j, int n);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *theString);
long	ft_atol(const char *theString);
int		ft_isdigit(int character);
int		ft_strlen(const char *theString);
int		is_valid_int(char *str);
t_list	*new_list(int value);
void	ft_lstclearall(t_list **lst);
int		add_to_list(t_list **stack, int value);
void	parse_argument(int argc, char **str, t_list **stack);
size_t	ft_strcspn(const char *s, const char *reject);
int		ft_delimiters(char c, const char *delimiters);
char	*ft_strtok(char *str, char const *delimiters);
void	parse_one_argument(char *str, t_list **stack);
void	free_lst(t_list **stack);
// Fonction principale
void	push_swap(t_list **stack_a, t_list **stack_b);

#endif
