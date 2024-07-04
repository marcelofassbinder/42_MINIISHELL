/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:18:18 by vivaccar          #+#    #+#             */
/*   Updated: 2024/07/04 20:56:51 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(char **cmd_args, t_shell *shell)
{
	int	i;

	i = 1;
	while (cmd_args[i])
	{
		ft_printf(STDOUT_FILENO, "%s", cmd_args[i]);
		i++;
		if (cmd_args[i])
			ft_printf(STDOUT_FILENO, " ");
	}
	ft_printf(STDOUT_FILENO, "\n");
	shell->exit_status = EXIT_SUCCESS;
}