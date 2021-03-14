/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_uniforms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:33 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/09 20:38:19 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				set_uniform_mat4(GLuint id, char *name, float m[][4])
{
	GLuint			loc;

	loc = glGetUniformLocation(id, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, (float *)m[0]);
}

void				set_uniform_int(GLuint id, char *name, int v)
{
	GLuint			loc;

	loc = glGetUniformLocation(id, name);
	glUniform1i(loc, v);
}

void				set_uniform_float(GLuint id, char *name, float v)
{
	GLuint			loc;

	loc = glGetUniformLocation(id, name);
	glUniform1f(loc, v);
}
