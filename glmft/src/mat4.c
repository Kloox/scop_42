/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:46:13 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 07:31:25 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmft.h"

void				mat4_free(float **m)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void				mat4_copy(float **dest, float **src)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			dest[i][k] = src[i][k];
			k++;
		}
		i++;
	}
}

void				mat4_mult(float **dest, float **l, float **r)
{
	float			**m;
	int				i;
	int				k;

	i = 0;
	k = 0;
	m = mat4_init(0.0f);
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			m[i][k] =
				l[0][k] * r[i][0] +
				l[1][k] * r[i][1] +
				l[2][k] * r[i][2] +
				l[3][k] * r[i][3];
			k++;
		}
		i++;
	}
	mat4_copy(dest, m);
	mat4_free(m);
}

float				**mat4_set(float **m, float v)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			m[i][k] = v;
			k++;
		}
		i++;
	}
	return (m);
}

float				**mat4_init(float v)
{
	float			**m;
	const size_t	gsize = sizeof(float *) * 4;
	const size_t	ssize = sizeof(float) * 4;

	m = (float **)malloc(gsize);
	m[0] = (float *)malloc(ssize);
	m[1] = (float *)malloc(ssize);
	m[2] = (float *)malloc(ssize);
	m[3] = (float *)malloc(ssize);
	return (mat4_set(m, v));
}
