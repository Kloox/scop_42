/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:21:08 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:21:38 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				build_texture_parameters(t_window_mgt **winmgt)
{
	glGenTextures(1, &((*winmgt)->gl_state.texture));
	glBindTexture(GL_TEXTURE_2D, (*winmgt)->gl_state.texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, \
	GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (set_texture((*winmgt)->text_bind == NULL ? \
	"chaton.bmp" : (*winmgt)->text_bind))
		(*winmgt)->ret_code = 8;
}

void				build_vaos(void)
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), \
	(void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), \
	(void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), \
	(void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void				build_gl_data(t_window_mgt **winmgt)
{
	float			*vertices;
	unsigned int	*indices;

	vertices = (*winmgt)->obj->vertices;
	indices = (*winmgt)->obj->indices;
	build_shaders(winmgt);
	glGenVertexArrays(1, &((*winmgt)->gl_state.vao));
	glGenBuffers(1, &((*winmgt)->gl_state.vbo));
	glGenBuffers(1, &((*winmgt)->gl_state.ebo));
	glBindVertexArray((*winmgt)->gl_state.vao);
	glBindBuffer(GL_ARRAY_BUFFER, (*winmgt)->gl_state.vbo);
	printf("Binding %d Vertices: Size: (v_size * sizeof(float)) = %ld\n", \
	(*winmgt)->obj->v_size / 8, (*winmgt)->obj->v_size * sizeof(float));
	glBufferData(GL_ARRAY_BUFFER, (*winmgt)->obj->v_size * sizeof(float), \
	vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (*winmgt)->gl_state.ebo);
	printf("Binding %d faces: %d points: SIZE(i_size*sizeof(int)): %ld\n", \
	(*winmgt)->obj->nb_indices, (*winmgt)->obj->i_size, \
	(*winmgt)->obj->i_size * sizeof(int));
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, \
	(*winmgt)->obj->i_size * sizeof(int), indices, GL_STATIC_DRAW);
	build_vaos();
	build_texture_parameters(winmgt);
	glUseProgram((*winmgt)->gl_state.shader_program);
}
