/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:38:50 by vivaccar          #+#    #+#             */
/*   Updated: 2024/06/18 12:52:49 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	char	*line;
	int		i = 0;

	start_sigaction();
	while (1)
	{
		i = 0;
		line = readline("minishell --> ");
		if (!line)
		{
			ft_printf(1, "exit\n");
			free(line);
			exit(0);
		}
		tokenizer(line);
		free(line);
	}
}