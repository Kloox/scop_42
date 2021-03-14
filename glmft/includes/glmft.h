/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glmft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:46:33 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 08:16:32 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLMFT_H
# define GLMFT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define NEAR 0.01f
# define FAR 100.f

/*
** ****************************** Structs *************************************
*/

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			a;
}					t_vec4;

/*
** ****************************** Funcs ***************************************
*/

/*
** vec3.c
*/
t_vec3				vec3_sub(t_vec3 l, t_vec3 r);
t_vec3				vec3_add(t_vec3 l, t_vec3 r);
t_vec3				vec3_mult_float(t_vec3 l, float f);
t_vec3				vec3_normalize(t_vec3 v);
t_vec3				vec3_mult_cross(t_vec3 l, t_vec3 r);

/*
** mat4.c
*/
void				mat4_free(float **m);
void				mat4_copy(float **dest, float **src);
void				mat4_mult(float **dest, float **l, float **r);
float				**mat4_set(float **m, float v);
float				**mat4_init(float v);

/*
** mat4_transform.c
*/
float				**mat4_look_at(float **dest, t_vec3 a, t_vec3 b, t_vec3 c);
float				**mat4_perspective(float **dest, float fovy, float aspect);
float				**mat4_translate(float **m, t_vec3 v);
float				**mat4_identity(float **m);
void				mat4_translate_in_place(float **m, float x, float y, \
					float z);
float				vec3_dot(t_vec3 a, t_vec3 b);

/*
** mat4_rotation.c
*/
void				rotate_y(float **dest, float **m, float angle);
void				mat4_mul_rot(float **dest, float **m1, float **m2);
void				mat4_mult_rot2(float **dest, float **m2, float **m1tmp);

/*
** utils.c
*/
float				degrees_to_radians(float d);

#endif
