/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:05 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 08:25:15 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		custom_key_hooks(t_window_mgt **winmgt)
{
	if (glfwGetKey((*winmgt)->win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose((*winmgt)->win, 1);
	mouse_hook(winmgt);
	graphics_hook(winmgt);
	cam_hook(winmgt);
}

void		mouse_hook(t_window_mgt **winmgt)
{
	int		state;
	double	xpos;
	double	ypos;

	state = glfwGetMouseButton((*winmgt)->win, GLFW_MOUSE_BUTTON_LEFT);
	glfwGetCursorPos((*winmgt)->win, &xpos, &ypos);
	if (!(*winmgt)->cam.first)
	{
		(*winmgt)->cam.lastxpos = xpos;
		(*winmgt)->cam.lastypos = ypos;
		(*winmgt)->cam.first = true;
	}
	if ((xpos != (*winmgt)->cam.lastxpos || ypos != (*winmgt)->cam.lastypos))
		mouse_move_cam(winmgt, xpos, ypos, state);
}

void		mouse_move_cam(t_window_mgt **winmgt, double xpos, \
			double ypos, int state)
{
	float	xoffset;
	float	yoffset;

	xoffset = xpos - (*winmgt)->cam.lastxpos;
	yoffset = ypos - (*winmgt)->cam.lastypos;
	(*winmgt)->cam.lastxpos = xpos;
	(*winmgt)->cam.lastypos = ypos;
	if (state == GLFW_PRESS)
	{
		xoffset += MOUSE_SENSIVITY;
		yoffset += MOUSE_SENSIVITY;
		(*winmgt)->cam.yaw += xoffset;
		(*winmgt)->cam.pitch += yoffset;
		if ((*winmgt)->cam.pitch > 89.0f)
			(*winmgt)->cam.pitch = 89.0f;
		if ((*winmgt)->cam.pitch < -89.0f)
			(*winmgt)->cam.pitch = -89.0f;
		(*winmgt)->cam.cam_front = vec3_normalize(get_front(winmgt));
	}
}
