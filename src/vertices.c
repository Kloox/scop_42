/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:53:24 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/24 12:11:14 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_obj_file			*normalize_vertices(t_obj_file *obj)
{
	unsigned int	c;

	c = 0;
	while (c < obj->v_size)
	{
		obj->vertices[c] = obj->vertices[c] / obj->maxs.x;
		obj->vertices[c + 1] = obj->vertices[c + 1] / obj->maxs.x;
		obj->vertices[c + 2] = obj->vertices[c + 2] / obj->maxs.x;
		c += VERTICE_SIZE;
	}
	return (obj);
}

void				assign_center(t_obj_file *obj, float *vert, t_vec3 center)
{
	int				i;
	float			tx;
	float			angle;

	angle = 90 * (M_PI / 180);
	i = 0;
	tx = 0.0f;
	while ((unsigned int)i < obj->v_size)
	{
		vert[i] -= center.x;
		vert[i + 1] -= center.y;
		vert[i + 2] -= center.z;
		tx = vert[i] * cos(angle) - vert[i + 2] * sin(angle);
		vert[i + 2] = vert[i] * sin(angle) + vert[i + 2] * cos(angle);
		vert[i] = tx;
		i += 8;
	}
}

void				center_vertices(t_obj_file *obj)
{
	int				i;
	float			*vert;
	t_vec3			max;
	t_vec3			min;

	i = 0;
	vert = obj->vertices;
	max.x = 0;
	max.y = 0;
	max.z = 0;
	min.x = 0;
	min.y = 0;
	min.z = 0;
	while ((unsigned int)i < obj->v_size)
	{
		vert[i] > max.x ? max.x = vert[i] : 0;
		vert[i + 1] > max.y ? max.y = vert[i + 1] : 0;
		vert[i + 2] > max.z ? max.z = vert[i + 2] : 0;
		vert[i] < min.x ? min.x = vert[i] : 0;
		vert[i + 1] < min.y ? min.y = vert[i + 1] : 0;
		vert[i + 2] < min.z ? min.z = vert[i + 2] : 0;
		i += 8;
	}
	assign_center(obj, vert, vec3_mult_float(vec3_add(max, min), 0.5));
}
