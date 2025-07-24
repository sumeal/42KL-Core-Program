/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:46:30 by muzz              #+#    #+#             */
/*   Updated: 2025/02/11 15:00:27 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	long			num;
	long			index;
	long			step;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	long	size;
}	t_stack;

void	ft_check_valid(int argc, char **argv);
void	ft_error(t_stack *stack_a, t_stack *stack_b);
void	ft_lstadd(t_stack **a, t_node *new);
t_node	*ft_lstnew(long num, int index);
void	ft_init_stack(t_stack **a, int argc, char **argv);
void	ft_free_stack(t_stack *a);
int		ft_is_sorted(t_stack *a);
t_node	*ft_lstlast(t_node *lst);
void	ft_sort_stack(t_stack *a, t_stack *b);
void	ft_sort_algo(t_stack *a, t_stack *b);
void	ft_sort_3(t_stack *a);
void	assign_indices(t_stack *a);
void	copy_stack_to_array(t_stack *a, long *arr);
long	find_min_value(long *arr, int size);
void	adjust_array_values(long *arr, int size, long offset);
void	bubble_sort(long *arr, int size);
long	*prepare_sorted_array(t_stack *a, long *offset);
void	assign_stack_indices(t_stack *a, long *arr, long offset);
void	assign_indices(t_stack *a);
void	ft_push_extreme(t_stack *a, t_stack *b, int find_largest);
void	ft_sort_4(t_stack *a, t_stack *b);
long	ft_atol(char *nptr);
void	ft_free_split(char **str);

//operations
void	ft_pa(t_stack *a, t_stack *b, int i);
void	ft_pb(t_stack *a, t_stack *b, int i);
void	ft_sa(t_stack *a, int i);
void	ft_sb(t_stack *b, int i);
void	ft_ss(t_stack *a, t_stack *b, int i);
void	ft_ra(t_stack *a, int i);
void	ft_rb(t_stack *b, int i);
void	ft_rr(t_stack *a, t_stack *b, int i);
void	ft_rra(t_stack *a, int i);
void	ft_rrb(t_stack *b, int i);
void	ft_rrr(t_stack *a, t_stack *b, int i);

#endif