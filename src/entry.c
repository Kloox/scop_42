/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:05 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/11 21:28:43 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			free_state(t_entry *state)
{
	free(state);
	return (1);
}

int			do_version(t_window_mgt **winmgt, t_entry *state, char **av, int *i)
{
	int len;

	if (!(state->seen_v) && av[(*i) + 1] && atof(av[(*i) + 1]))
	{
		state->custom_v = ft_strsplit(av[(*i) + 1], '.');
		len = ft_tablen(state->custom_v);
		if (state->custom_v != NULL && len == 2)
		{
			(*winmgt)->major = ft_atoi(state->custom_v[0]);
			(*winmgt)->minor = ft_atoi(state->custom_v[1]);
			if (version_is_valid(winmgt))
			{
				(*winmgt)->custom_version = true;
				state->seen_v++;
			}
			else
				return (1);
		}
		else
			return (1);
		(*i)++;
	}
	else
		return (1);
	return (0);
}

int			parse_file(t_window_mgt **winmgt, char **av, int *i)
{
	if (is_valid_file(av[(*i)]))
	{
		if (parse_obj_file(winmgt, av[(*i)]))
			return (printf("Error: Parsing error in %s\n", av[(*i)]));
	}
	else
		return (1);
	return (0);
}

int			parse_entry(t_window_mgt **winmgt, t_entry *state, char **av, \
			int *i)
{
	int ret;

	ret = 0;
	if (!ft_strcmp(av[(*i)], "-r") || !ft_strcmp(av[(*i)], "--refresh-rate"))
		ret = do_refresh_rate(state, av, i) ? free_state(state) : 0;
	else if (!ft_strcmp(av[(*i)], "-w") || !ft_strcmp(av[(*i)], "--width"))
		ret = do_res_width(state, av, i) ? free_state(state) : 0;
	else if (!ft_strcmp(av[(*i)], "-t") || !ft_strcmp(av[(*i)], "--texture"))
		ret = do_texture(winmgt, state, av, i) ? free_state(state) : 0;
	else if (!ft_strcmp(av[(*i)], "-h") || !ft_strcmp(av[(*i)], "--height"))
		ret = do_res_height(state, av, i) ? free_state(state) : 0;
	else if (!ft_strcmp(av[(*i)], "-f") || !ft_strcmp(av[(*i)], "--fullscreen"))
	{
		if (!(*winmgt)->fullscreen)
			(*winmgt)->fullscreen = true;
		else
			return (1);
	}
	else if (!ft_strcmp(av[(*i)], "-v") || !ft_strcmp(av[(*i)], "--version"))
		ret = do_version(winmgt, state, av, i) ? free_state(state) : 0;
	else
		ret = parse_file(winmgt, av, i);
	(*i)++;
	return (ret);
}

int			manage_entry(t_window_mgt **winmgt, int ac, char **av)
{
	t_entry	*state;
	int		i;

	state = (t_entry*)malloc(sizeof(t_entry));
	memset(state, 0, sizeof(t_entry));
	i = 1;
	if (ac < 2 || ac > 13)
		return (free_state(state));
	while (i < ac + 1)
	{
		if (av[i] == NULL || i >= ac)
			break ;
		if (parse_entry(winmgt, state, av, &i))
			return (1);
	}
	if (state->custom_rr)
		(*winmgt)->refresh_rate = state->custom_rr;
	if (state->custom_w)
		(*winmgt)->width = state->custom_w;
	if (state->custom_h)
		(*winmgt)->height = state->custom_h;
	if (state->custom_v != NULL)
		ft_free_words_tables(&(state->custom_v));
	free(state);
	return (0);
}
