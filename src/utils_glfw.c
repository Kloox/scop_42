/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_glfw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:39 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/09 19:16:51 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					clean_glfw(t_window_mgt *winmgt, char *reason)
{
	printf("Exiting...\nReason : %s\n", reason);
	glfwDestroyWindow(winmgt->win);
	glfwTerminate();
	free_scop(winmgt);
	return (1);
}

void				init_window_hints(t_window_mgt **winmgt)
{
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
	glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
	glfwInitHint(GLFW_COCOA_MENUBAR, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,
	(*winmgt)->custom_version ? (*winmgt)->major : OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,
	(*winmgt)->custom_version ? (*winmgt)->minor : OPENGL_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	if ((*winmgt)->width == 0)
		(*winmgt)->width = WIDTH_DEFAULT;
	if ((*winmgt)->height == 0)
		(*winmgt)->height = HEIGHT_DEFAULT;
	if ((*winmgt)->refresh_rate == 0)
		(*winmgt)->refresh_rate = mode->refreshRate;
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, (*winmgt)->refresh_rate);
}

void				init_glfw(t_window_mgt **winmgt)
{
	glfwSetErrorCallback(error_callback);
	if (glfwInit())
	{
		init_window_hints(winmgt);
		(*winmgt)->win = glfwCreateWindow((*winmgt)->width,
										(*winmgt)->height,
										WIN_TITLE,
										(*winmgt)->fullscreen ?
										glfwGetPrimaryMonitor() : NULL,
										NULL);
		glfwSetWindowAttrib((*winmgt)->win, GLFW_RESIZABLE, GLFW_TRUE);
		glfwMakeContextCurrent((*winmgt)->win);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwSwapInterval(1);
		glfwGetFramebufferSize((*winmgt)->win,
		&((*winmgt)->width), &((*winmgt)->height));
		glViewport(0, 0, (*winmgt)->width, (*winmgt)->height);
		glfwSetInputMode((*winmgt)->win, GLFW_STICKY_KEYS, GLFW_TRUE);
		glfwSetScrollCallback((*winmgt)->win, scroll_callback);
		printf("Version = %s\nVendor = %s\nRenderer: %s\n",
		(char *)(glGetString(GL_VERSION)), (char *)(glGetString(GL_VENDOR)),
		(char *)(glGetString(GL_RENDERER)));
	}
	else
		(*winmgt)->ret_code = 2;
}

int					set_texture(char *name)
{
	t_texture_file	*tf;

	tf = get_file_texture(name);
	if (tf == NULL)
		return (1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
	tf->width, tf->height, 0, GL_BGR, GL_UNSIGNED_BYTE, tf->data);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(tf->header);
	free(tf->data);
	free(tf);
	return (0);
}
