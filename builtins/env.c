/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:07:56 by vivaccar          #+#    #+#             */
/*   Updated: 2024/07/06 15:01:18 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(char **cmd_args, t_shell *shell)
{
	int		i;

	if (cmd_args[1])
	{
		ft_printf(STDERR_FILENO, "env '%s': no such file or directory\n", cmd_args[1]);
		shell->exit_status = EXIT_CMD;
		safe_exit(shell);
	}
	i = 0;
	while (shell->envp[i])
	{
		ft_printf(1, "%s\n", shell->envp[i]);
		i++;
	}
	shell->exit_status = EXIT_SUCCESS;
}
