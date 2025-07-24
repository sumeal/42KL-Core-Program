/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:09:09 by muzz              #+#    #+#             */
/*   Updated: 2025/02/11 15:23:33 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_int_range(char *arg)
{
	long	num;

	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

static int	ft_check_valid2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j])
				|| argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			else
				return (1);
		}
		if (ft_check_int_range(argv[i]) == 1)
			return (1);
		i++;
	}
	if (ft_check_duplicates(argc, argv) == 1)
		return (1);
	return (0);
}

void	ft_check_valid(int argc, char **argv)
{
	char	**args;
	int		arg_count;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error(NULL, NULL);
		arg_count = 0;
		while (args[arg_count])
			arg_count++;
		if (ft_check_valid2(arg_count, args) == 1)
		{
			ft_free_split(args);
			ft_error(NULL, NULL);
		}
	}
	else
		if (ft_check_valid2(argc, argv) == 1)
			ft_error(NULL, NULL);
}
