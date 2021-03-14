/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:46:26 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 08:04:08 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmft.h"

t_vec3		vec3_sub(t_vec3 l, t_vec3 r)
{
	t_vec3	dst;

	dst.x = l.x - r.x;
	dst.y = l.y - r.y;
	dst.z = l.z - r.z;
	return (dst);
}

t_vec3		vec3_add(t_vec3 l, t_vec3 r)
{
	t_vec3	dst;

	dst.x = l.x + r.x;
	dst.y = l.y + r.y;
	dst.z = l.z + r.z;
	return (dst);
}

t_vec3		vec3_mult_float(t_vec3 l, float f)
{
	t_vec3	dst;

	dst.x = l.x * f;
	dst.y = l.y * f;
	dst.z = l.z * f;
	return (dst);
}

t_vec3		vec3_normalize(t_vec3 v)
{
	t_vec3	ret;
	float	m;

	m = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	ret.x = v.x / m;
	ret.y = v.y / m;
	ret.z = v.z / m;
	return (ret);
}

t_vec3		vec3_mult_cross(t_vec3 l, t_vec3 r)
{
	t_vec3	ret;

	ret.x = l.y * r.z - l.z * r.y;
	ret.y = l.z * r.x - l.x * r.z;
	ret.z = l.x * r.y - l.y * r.x;
	return (ret);
}
