/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:35 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 08:31:01 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error_callback(int code, const char *description)
{
	printf("GLFW Error: Code %d : %s\n", code, description);
	exit(EXIT_FAILURE);
}

void	scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	(void)window;
	(void)xoffset;
	g_zoom -= (float)yoffset * 2;
	if (g_zoom < 1.0f)
		g_zoom = 1.0f;
	if (g_zoom > 60.0f)
		g_zoom = 60.0f;
}
