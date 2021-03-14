/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:46:19 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 07:58:55 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmft.h"

float			**mat4_translate(float **m, t_vec3 v)
{
	float		**translate;

	translate = mat4_init(0.0f);
	translate = mat4_identity(translate);
	translate[0][3] = v.x;
	translate[1][3] = v.y;
	translate[2][3] = v.z;
	mat4_mult(m, m, translate);
	mat4_free(translate);
	return (m);
}

float			vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float			**mat4_look_at(float **dest, t_vec3 eye, \
				t_vec3 center, t_vec3 up)
{
	t_vec3		f;
	t_vec3		s;

	f = vec3_sub(center, eye);
	f = vec3_normalize(f);
	s = vec3_mult_cross(f, up);
	s = vec3_normalize(s);
	dest[0][0] = s.x;
	dest[0][1] = vec3_mult_cross(s, f).x;
	dest[0][2] = -(f.x);
	dest[0][3] = 0.0f;
	dest[1][0] = s.y;
	dest[1][1] = vec3_mult_cross(s, f).y;
	dest[1][2] = -(f.y);
	dest[1][3] = 0.0f;
	dest[2][0] = s.z;
	dest[2][1] = vec3_mult_cross(s, f).z;
	dest[2][2] = -(f.z);
	dest[2][3] = 0.0f;
	dest[3][0] = -vec3_dot(s, eye);
	dest[3][1] = -vec3_dot(vec3_mult_cross(s, f), eye);
	dest[3][2] = vec3_dot(f, eye);
	dest[3][3] = 1.0f;
	return (dest);
}

float			**mat4_perspective(float **m, float fovy, \
				float aspect)
{
	float		a;

	a = 1.f / tanf(fovy / 2.f);
	m = mat4_set(m, 0.0f);
	m[0][0] = a / aspect;
	m[0][1] = 0.f;
	m[0][2] = 0.f;
	m[0][3] = 0.f;
	m[1][0] = 0.f;
	m[1][1] = a;
	m[1][2] = 0.f;
	m[1][3] = 0.f;
	m[2][0] = 0.f;
	m[2][1] = 0.f;
	m[2][2] = -((FAR + NEAR) / (FAR - NEAR));
	m[2][3] = -1.f;
	m[3][0] = 0.f;
	m[3][1] = 0.f;
	m[3][2] = -((2.f * FAR * NEAR) / (FAR - NEAR));
	m[3][3] = 0.f;
	return (m);
}

float			**mat4_identity(float **m)
{
	m = mat4_set(m, 0.0f);
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
	m[3][3] = 1.0f;
	return (m);
}
