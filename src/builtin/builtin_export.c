/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:12 by gpaeng            #+#    #+#             */
/*   Updated: 2022/02/10 20:07:04 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mush.h"
#include <stdio.h>

char	**env_deepcpy(t_state *state)
{
	char	**env;
	int		cnt_env_arr;
	int		i;

	cnt_env_arr = ft_cnt_arg(state->envp);
	env = (char **)ft_set_malloc(sizeof(char *), cnt_env_arr + 1);
	i = 0;
	while (cnt_env_arr-- > 0 && state->envp[cnt_env_arr])
	{
		env[i] = ft_strdup(state->envp[i]);
		i++;
	}
	return (env);
}

void	ft_print_env_export(t_state *state)
{
	char	**state_cpy;
	char	*path_name;
	char	*path_value;
	int		i;
	int		j;
	// char	*ptr;

	i = 0;
	state_cpy = env_deepcpy(state);
	bubble_sort_envp(state_cpy);
	while (state_cpy[i])
	{
		j = ft_strlchr(state_cpy[i], '=');
		path_name = ft_strndup(state_cpy[i], j);
		path_value = ft_strndup(state_cpy[i]+j+1, ft_strlen(state_cpy[i]) - j);
		// ptr = state_cpy[i];
		// path_name = strsep(&ptr, "=");
		// path_value = ptr;
		printf("declare -x %s=\"%s\"\n", path_name, path_value);
		free(path_name);
		free(path_value);
		free(state_cpy[i]);
		i++;
	}
	free(state_cpy);
}

void	ft_update_env_export(t_state *state, char *argv[])
{
	char	**env;
	int		cnt_env_arr;
	int		i;

	cnt_env_arr = ft_cnt_arg(state->envp);
	env = (char **)ft_set_malloc(sizeof(char *), cnt_env_arr + 2);
	i = 0;
	if (ft_check_arg_form(argv))
	{
		while (state->envp[i] && i < cnt_env_arr)
		{
			env[i] = ft_strdup(state->envp[i]);
			i++;
		}
		env[i] = ft_strdup(argv[1]);
		state->envp = env;
	}
	return ;
}

int	builtin_export(t_state *state, int argc, char *argv[])
{
	if (argc == 1)
		ft_print_env_export(state);
	else if (argc >= 2)
		ft_update_env_export(state, argv);
	return (0);
}
