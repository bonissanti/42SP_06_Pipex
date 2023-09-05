/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:48:37 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/05 18:48:38 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex);
	if (!check_args(argc, argv, &pipex))
	{
		cleanup(&pipex);
		return (1);
	}
	ft_parse_cmds(argv, &pipex, envp);
	if (!pipex.cmd_paths)
	{
		cleanup(&pipex);
		return (1);
	}
	exec_cmds(&pipex);
	cleanup(&pipex);
	return (0);
}
