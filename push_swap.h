/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:54:59 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/29 08:54:01 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

# define MALLOC_FAILED "syscall: malloc failed"
# define WRITE_FAILED "syscall: write failed"

typedef struct t_node
{
	int		nb;
	struct t_node *next;
}	t_node;

typedef struct t_stack
{
	struct t_node	*first;
}	t_stack;

typedef struct t_data
{
	struct t_stack	*stack_a;
	struct t_stack	*stack_b;
	int				*input;
	char			*join_args;
	int				input_count;
}	t_data;

#include "commands.h"

void	init_stacks(t_data *data);
void	free_and_exit(const char *err, int code, t_data *data);
t_node	*find_higher(t_stack *stack);
t_node	*find_lowest(t_stack *stack);
int		find_index(t_node *node, t_stack *stack);
void	parse(char *arg, t_data *data);
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	free_and_exit(const char *err, int code, t_data *data);
bool	is_sorted(t_data *data);
void	input_to_array(char **argv, t_data *data);

#endif