/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:37:40 by vivaccar          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:29 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**prepare_to_delete(t_shell *shell, int	*k, int *i, int *j)
{
	char **new_envs;

	*i = 0;
	while (shell->envp[*i])
		(*i)++;
	new_envs = ft_calloc(sizeof(char *), *i);
	if (!new_envs)
		shell_error(shell, "Calloc Error: Remove env\n", 0, true);
	*j = *i;
	*i = 0;
	*k = 0;
	return (new_envs);
}

char	**remove_env(char *to_remove, t_shell *shell)
{
	int		i;
	char	**new_envs;
	int		j;
	char	*cur_var;
	int		k;

	new_envs = prepare_to_delete(shell, &k, &i, &j);
	while (i < j)
	{
		cur_var = get_variable_name(shell->envp[i]);
		if (!ft_strcmp(to_remove, cur_var))
		{
			i++;
			free(cur_var);
			continue ;
		}
		new_envs[k] = ft_strdup(shell->envp[i]);
		free(cur_var);
		i++;
		k++;
	}
	i = 0;
	free_envs(shell->envp);
	return (new_envs);
}

char	**delete_envp(char *environment, t_shell *shell)
{
	int		i;
	char	*cur_var;
	char	**new_envs;

	i = 0;
	new_envs = NULL;
	while (shell->envp[i])
	{
		cur_var = get_variable_name(shell->envp[i]);
		if (!ft_strcmp(environment, cur_var))
		{
			new_envs = remove_env(cur_var, shell);
			free (cur_var);
			return (new_envs);
		}
		free(cur_var);
		i++;
	}
	return (shell->envp);
}

void	unset(char **cmd_args, t_shell *shell)
{
	int	i;

	i = 1;
	shell->exit_status = EXIT_SUCCESS;
	while (cmd_args[i])
	{
		if (cmd_args[i][0] == '-')
		{
			ft_printf(2, "minishell: unset '%s': not a valid identifier\n", cmd_args[i]);
			shell->exit_status = 2;
			i++;
			continue ;
		}
		shell->envp = delete_envp(cmd_args[i], shell);
		i++;
	}
}