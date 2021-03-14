/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:46:16 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 07:52:57 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmft.h"

void			rotate_y(float **dest, float **m, float angle)
{
	float		**t;
	float		c;
	float		s;

	t = mat4_init(0.f);
	t = mat4_identity(t);
	c = cosf(angle);
	s = sinf(angle);
	t[0][0] = c;
	t[0][2] = -s;
	t[2][0] = s;
	t[2][2] = c;
	mat4_mul_rot(dest, m, t);
	mat4_free(t);
}

void			mat4_mult_rot2(float **dest, float **m2, float **m1tmp)
{
	dest[2][0] = m1tmp[0][0] * m2[2][0] + m1tmp[1][0] * \
	m2[2][1] + m1tmp[2][0] * m2[2][2];
	dest[2][1] = m1tmp[0][1] * m2[2][0] + m1tmp[1][1] * \
	m2[2][1] + m1tmp[2][1] * m2[2][2];
	dest[2][2] = m1tmp[0][2] * m2[2][0] + m1tmp[1][2] * \
	m2[2][1] + m1tmp[2][2] * m2[2][2];
	dest[2][3] = m1tmp[0][3] * m2[2][0] + m1tmp[1][3] * \
	m2[2][1] + m1tmp[2][3] * m2[2][2];
	dest[3][0] = m1tmp[3][0];
	dest[3][1] = m1tmp[3][1];
	dest[3][2] = m1tmp[3][2];
	dest[3][3] = m1tmp[3][3];
}

void			mat4_mul_rot(float **dest, float **m1, float **m2)
{
	float		**m1tmp;

	m1tmp = mat4_init(0.f);
	mat4_copy(m1tmp, m1);
	dest[0][0] = m1tmp[0][0] * m2[0][0] + m1tmp[1][0] * \
	m2[0][1] + m1tmp[2][0] * m2[0][2];
	dest[0][1] = m1tmp[0][1] * m2[0][0] + m1tmp[1][1] * \
	m2[0][1] + m1tmp[2][1] * m2[0][2];
	dest[0][2] = m1tmp[0][2] * m2[0][0] + m1tmp[1][2] * \
	m2[0][1] + m1tmp[2][2] * m2[0][2];
	dest[0][3] = m1tmp[0][3] * m2[0][0] + m1tmp[1][3] * \
	m2[0][1] + m1tmp[2][3] * m2[0][2];
	dest[1][0] = m1tmp[0][0] * m2[1][0] + m1tmp[1][0] * \
	m2[1][1] + m1tmp[2][0] * m2[1][2];
	dest[1][1] = m1tmp[0][1] * m2[1][0] + m1tmp[1][1] * \
	m2[1][1] + m1tmp[2][1] * m2[1][2];
	dest[1][2] = m1tmp[0][2] * m2[1][0] + m1tmp[1][2] * \
	m2[1][1] + m1tmp[2][2] * m2[1][2];
	dest[1][3] = m1tmp[0][3] * m2[1][0] + m1tmp[1][3] * \
	m2[1][1] + m1tmp[2][3] * m2[1][2];
	mat4_mult_rot2(dest, m2, m1tmp);
	mat4_free(m1tmp);
}
