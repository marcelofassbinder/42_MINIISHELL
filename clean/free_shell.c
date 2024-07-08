/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:17:12 by vivaccar          #+#    #+#             */
/*   Updated: 2024/07/08 18:44:01 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_envs(char **envp)
{
	int	i;

	i = 0;
	while(envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	free_and_exit(t_shell *shell)
{
	int status;

	status = shell->exit_status;
	if (shell->token_list)
	{
		if (shell->token_list->first)
			free_token_list(shell->token_list);
		free(shell->token_list);
	}
	if (shell->root)
		free_tree(shell->root);
	if (shell->line)
		free(shell->line);
	if (shell->old_pwd)
		free(shell->old_pwd);
	if (shell)
		free(shell);
	exit(status);
}