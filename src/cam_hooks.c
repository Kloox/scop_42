/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:53:24 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/09 18:59:57 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				cam_hook(t_window_mgt **winmgt)
{
	const double	ts = glfwGetTime();
	const float		camera_speed = CAM_SPEED;

	cam_hooks_ws(winmgt, ts, camera_speed);
	cam_hooks_da(winmgt, ts, camera_speed);
	cam_hooks_up_down(winmgt, ts, camera_speed);
	cam_hooks_right_left(winmgt, ts, camera_speed);
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + HOOK_BIG_DELAY) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->sleep = (*winmgt)->sleep ? false : true;
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			init_mats(winmgt, 0);
			g_zoom = 45.0f;
		}
	}
}

void				cam_hooks_ws(t_window_mgt **winmgt, double ts, \
					const float camera_speed)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_sub((*winmgt)->cam.cam_pos,\
			vec3_mult_float((*winmgt)->cam.cam_up, camera_speed));
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_add((*winmgt)->cam.cam_pos, \
			vec3_mult_float((*winmgt)->cam.cam_up, camera_speed));
		}
	}
}

void				cam_hooks_da(t_window_mgt **winmgt, double ts, \
					const float camera_speed)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_sub((*winmgt)->cam.cam_pos, \
			vec3_mult_float(vec3_normalize(vec3_mult_cross(\
			(*winmgt)->cam.cam_front, (*winmgt)->cam.cam_up)), camera_speed));
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_add((*winmgt)->cam.cam_pos, \
			vec3_mult_float(vec3_normalize(vec3_mult_cross(\
			(*winmgt)->cam.cam_front, (*winmgt)->cam.cam_up)), camera_speed));
		}
	}
}

void				cam_hooks_up_down(t_window_mgt **winmgt, double ts, \
					const float camera_speed)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_add((*winmgt)->cam.cam_pos, \
			vec3_mult_float((*winmgt)->cam.cam_front, camera_speed));
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_sub((*winmgt)->cam.cam_pos, \
			vec3_mult_float((*winmgt)->cam.cam_front, camera_speed));
		}
	}
}

void				cam_hooks_right_left(t_window_mgt **winmgt, double ts, \
					const float camera_speed)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_sub((*winmgt)->cam.cam_pos, \
			vec3_mult_float((*winmgt)->cam.cam_right, camera_speed));
		}
	}
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		if (!(*winmgt)->delay || ((*winmgt)->delay + \
		(1.0f / (*winmgt)->refresh_rate)) < ts)
		{
			(*winmgt)->delay = ts;
			(*winmgt)->cam.cam_pos = vec3_add((*winmgt)->cam.cam_pos, \
			vec3_mult_float((*winmgt)->cam.cam_right, camera_speed));
		}
	}
}
