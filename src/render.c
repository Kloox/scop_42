/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:53:24 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/24 13:29:33 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		pass_uniforms(t_window_mgt **winmgt, float time)
{
	set_uniform_mvp(winmgt);
	set_uniform_float((*winmgt)->gl_state.shader_program, \
	"time", time);
	set_uniform_int((*winmgt)->gl_state.shader_program, \
	"texMap", (*winmgt)->texture_mapping);
	set_uniform_int((*winmgt)->gl_state.shader_program, \
	"colorType", (*winmgt)->color_type);
	set_uniform_int((*winmgt)->gl_state.shader_program, \
	"flip", (*winmgt)->flip);
}

void		compute_mvp_mats(t_window_mgt **winmgt, t_vec3 vadd)
{
	float	**tmp1;
	float	**rot1;

	tmp1 = mat4_init(0.f);
	rot1 = mat4_init(0.f);
	(*winmgt)->ms->projection = mat4_set((*winmgt)->ms->projection, 0.0f);
	(*winmgt)->ms->view = mat4_set((*winmgt)->ms->view, 0.0f);
	(*winmgt)->ms->view = mat4_identity((*winmgt)->ms->view);
	(*winmgt)->ms->model = mat4_set((*winmgt)->ms->model, 0.0f);
	(*winmgt)->ms->model = mat4_identity((*winmgt)->ms->model);
	(*winmgt)->ms->projection = mat4_perspective((*winmgt)->ms->projection, \
	degrees_to_radians(g_zoom), \
	(float)(*winmgt)->width / (float)(*winmgt)->height);
	vadd = vec3_add((*winmgt)->cam.cam_pos, (*winmgt)->cam.cam_front);
	(*winmgt)->ms->view = mat4_look_at((*winmgt)->ms->view, \
	(t_vec3){(*winmgt)->cam.cam_pos.x, (*winmgt)->cam.cam_pos.y, \
	(*winmgt)->cam.cam_pos.z}, (t_vec3){vadd.x, vadd.y, vadd.z}, \
	(t_vec3){(*winmgt)->cam.cam_up.x, (*winmgt)->cam.cam_up.y, \
	(*winmgt)->cam.cam_up.z});
	tmp1 = mat4_identity(tmp1);
	rot1 = mat4_identity(rot1);
	tmp1[3][3] = 1.5f;
	mat4_mult((*winmgt)->ms->model, rot1, tmp1);
	mat4_free(tmp1);
	mat4_free(rot1);
}

void		render(t_window_mgt **winmgt)
{
	float	time;
	t_vec3	vadd;

	time = glfwGetTime();
	compute_mvp_mats(winmgt, vadd);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, (*winmgt)->gl_state.texture);
	glUseProgram((*winmgt)->gl_state.shader_program);
	glBindVertexArray((*winmgt)->gl_state.vao);
	pass_uniforms(winmgt, time);
	glDrawElements(GL_TRIANGLES, (*winmgt)->obj->i_size, GL_UNSIGNED_INT, 0);
}
