/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:21:08 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:23:24 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				build_shaders_vertex(t_window_mgt **winmgt)
{
	const char		*vertex_shader_source = get_shader(winmgt, "pv.glsl");
	int				success;
	char			info_log[512];

	(*winmgt)->gl_state.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource((*winmgt)->gl_state.vertex_shader, 1, \
	&vertex_shader_source, NULL);
	glCompileShader((*winmgt)->gl_state.vertex_shader);
	free((char *)vertex_shader_source);
	glGetShaderiv((*winmgt)->gl_state.vertex_shader, GL_COMPILE_STATUS, \
	&success);
	if (!success)
	{
		glGetShaderInfoLog((*winmgt)->gl_state.vertex_shader, \
		512, NULL, info_log);
		printf("Compilation vertex shader error: %s\n", info_log);
		(*winmgt)->ret_code = 5;
	}
}

void				build_shaders_frag(t_window_mgt **winmgt)
{
	const char		*fragment_shader_source = get_shader(winmgt, "ps.glsl");
	int				success;
	char			info_log[512];

	(*winmgt)->gl_state.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource((*winmgt)->gl_state.fragment_shader, 1, \
	&fragment_shader_source, NULL);
	glCompileShader((*winmgt)->gl_state.fragment_shader);
	glGetShaderiv((*winmgt)->gl_state.fragment_shader, \
	GL_COMPILE_STATUS, &success);
	free((char *)fragment_shader_source);
	if (!success)
	{
		glGetShaderInfoLog((*winmgt)->gl_state.fragment_shader, \
		512, NULL, info_log);
		printf("Compilation frag shader error: %s\n", info_log);
		(*winmgt)->ret_code = 5;
	}
}

void				build_shaders(t_window_mgt **winmgt)
{
	int				success;

	build_shaders_vertex(winmgt);
	build_shaders_frag(winmgt);
	glGetProgramiv((*winmgt)->gl_state.shader_program,
	GL_LINK_STATUS, &success);
	(*winmgt)->gl_state.shader_program = glCreateProgram();
	glAttachShader((*winmgt)->gl_state.shader_program,
	(*winmgt)->gl_state.vertex_shader);
	glAttachShader((*winmgt)->gl_state.shader_program,
	(*winmgt)->gl_state.fragment_shader);
	glLinkProgram((*winmgt)->gl_state.shader_program);
	glDeleteShader((*winmgt)->gl_state.vertex_shader);
	glDeleteShader((*winmgt)->gl_state.fragment_shader);
}
