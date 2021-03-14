/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:02 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 09:57:42 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			graphics_hook(t_window_mgt **winmgt)
{
	double		ts;

	ts = glfwGetTime();
	graphics_hooks_opt(winmgt, ts);
	graphics_hooks_text_mapping(winmgt, ts);
	graphics_hooks_color_mapping(winmgt, ts);
	graphics_hooks_text_opt(winmgt, ts);
}

void			graphics_hooks_opt(t_window_mgt **winmgt, double ts)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_T) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->obj->texture = (*winmgt)->obj->texture ? false : true;
			set_uniform_int((*winmgt)->gl_state.shader_program, \
			"t", (*winmgt)->obj->texture ? 1 : 0);
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_9) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			if ((*winmgt)->text_bind)
				set_texture((*winmgt)->text_bind);
		}
	}
}

void			graphics_hooks_text_mapping(t_window_mgt **winmgt, double ts)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_1) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->texture_mapping = 0;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_2) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->texture_mapping = 1;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_3) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->texture_mapping = 2;
		}
	}
}

void			graphics_hooks_color_mapping(t_window_mgt **winmgt, double ts)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_4) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->color_type = 0;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_5) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->color_type = 1;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_6) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->color_type = 2;
		}
	}
}

void			graphics_hooks_text_opt(t_window_mgt **winmgt, double ts)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_7) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->texture_mapping = 3;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_8) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->flip = (*winmgt)->flip == 0 ? 1 : 0;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_K) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			set_texture("chaton.bmp");
		}
	}
}
