/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:57:07 by ibaby             #+#    #+#             */
/*   Updated: 2024/07/01 17:06:24 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "commands.h"

char	**get_commands(void);
void	execute(char *command, t_data *data);
void	sort(t_data *data);
bool	is_sorted(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		print_err_and_exit("ERROR", EXIT_FAILURE, false);
	ft_memset(&data, 0, sizeof(t_data));
	data.commands = get_commands();
	input_to_array(argv, &data);
	init_stacks(&data);
	sort(&data);
	if (is_sorted(&data) == true)
		free_and_exit("OK", EXIT_SUCCESS, &data);
	else
		free_and_exit("KO", EXIT_SUCCESS, &data);
}

char	**get_commands(void)
{
	char	**commands;
	char	*output;
	char	*temp;
	int		i;

	i = 0;
	output = ft_strdup("");
	if (output == NULL)
		print_err_and_exit(MALLOC_FAILED, EXIT_FAILURE, false);
	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break ;
		output = ft_re_strjoin(output, temp);
		free(temp);
		if (output == NULL)
			print_err_and_exit(MALLOC_FAILED, EXIT_FAILURE, false);
	}
	commands = ft_split(output, '\n');
	free(output);
	if (commands == NULL)
		print_err_and_exit("split function failed", EXIT_FAILURE, false);
	return (commands);
}

void	sort(t_data *data)
{
	char	**commands;
	int		i;

	i = 0;
	commands = data->commands;
	while (commands[i])
	{
		execute(commands[i], data);
		++i;
	}
}

void	execute(char *command, t_data *data)
{
	if (ft_strcmp(command, "pa") == 0)
		push_a(data);
	else if (ft_strcmp(command, "pb") == 0)
		push_b(data);
	else if (ft_strcmp(command, "sa") == 0)
		swap_a(data);
	else if (ft_strcmp(command, "sb") == 0)
		swap_b(data);
	else if (ft_strcmp(command, "ss") == 0)
		swap_ab(data);
	else if (ft_strcmp(command, "ra") == 0)
		rotate_a(data);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_b(data);
	else if (ft_strcmp(command, "rr") == 0)
		rotate_ab(data);
	else if (ft_strcmp(command, "rra") == 0)
		r_rotate_a(data);
	else if (ft_strcmp(command, "rrb") == 0)
		r_rotate_b(data);
	else if (ft_strcmp(command, "rrr") == 0)
		r_rotate_ab(data);
	else
		free_and_exit("Error", EXIT_FAILURE, data);
}

bool	is_sorted(t_data *data)
{
	t_node	*node;

	if (data->stack_b->first || !data->stack_a->first)
		return (false);
	node = data->stack_a->first;
	while (node->next)
	{
		if (node->nb > node->next->nb)
			return (false);
		node = node->next;
	}
	return (true);
}