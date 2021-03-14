/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:05 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/11 21:28:45 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			do_refresh_rate(t_entry *state, char **av, int *i)
{
	if (!(state->seen_rr) && av[(*i) + 1] && ft_atoi(av[(*i) + 1]))
	{
		state->custom_rr = ft_atoi(av[(*i) + 1]);
		if (state->custom_rr < REFRESH_RATE_MIN ||
			state->custom_rr > REFRESH_RATE_MAX)
			return (1);
		state->seen_rr++;
		(*i)++;
	}
	else
		return (1);
	return (0);
}

int			do_res_width(t_entry *state, char **av, int *i)
{
	if (!(state->seen_w) && av[(*i) + 1] && ft_atoi(av[(*i) + 1]))
	{
		state->custom_w = ft_atoi(av[(*i) + 1]);
		if (state->custom_w < WIDTH_MIN || state->custom_w > WIDTH_MAX)
			return (1);
		state->seen_w++;
		(*i)++;
	}
	else
		return (1);
	return (0);
}

int			do_texture(t_window_mgt **winmgt, t_entry *state, char **av, int *i)
{
	if (!(state->seen_tt) && av[(*i) + 1])
	{
		(*winmgt)->text_bind = av[(*i) + 1];
		state->seen_tt++;
		(*i)++;
	}
	else
		return (1);
	return (0);
}

int			do_res_height(t_entry *state, char **av, int *i)
{
	if (!(state->seen_h) && av[(*i) + 1] && ft_atoi(av[(*i) + 1]))
	{
		state->custom_h = ft_atoi(av[(*i) + 1]);
		if (state->custom_h < HEIGHT_MIN ||
			state->custom_h > HEIGHT_MAX)
			return (1);
		state->seen_h++;
		(*i)++;
	}
	else
		return (1);
	return (0);
}

int			version_is_valid(t_window_mgt **winmgt)
{
	if (
		((*winmgt)->major == 3 && (*winmgt)->minor == 3) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 0) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 1) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 2) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 3) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 4) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 5) ||
		((*winmgt)->major == 4 && (*winmgt)->minor == 6))
		return (1);
	return (0);
}
