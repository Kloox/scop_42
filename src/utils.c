/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:11 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/11 22:04:49 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			random_int(int min, int max)
{
	return (min + rand() % (max + 1 - min));
}

t_vec3		get_front(t_window_mgt **winmgt)
{
	t_vec3	front;

	front.x = cos(degrees_to_radians((*winmgt)->cam.yaw)) * \
	cos(degrees_to_radians((*winmgt)->cam.pitch));
	front.y = sin(degrees_to_radians((*winmgt)->cam.pitch));
	front.z = sin(degrees_to_radians((*winmgt)->cam.yaw)) * \
	cos(degrees_to_radians((*winmgt)->cam.pitch));
	return (front);
}

void		free_obj(t_obj_file *obj)
{
	if (obj->vertices != NULL)
		free(obj->vertices);
	if (obj->indices != NULL)
		free(obj->indices);
	if (obj->vt_tab != NULL)
		free(obj->vt_tab);
	if (obj->text_tab != NULL)
		free(obj->text_tab);
	free(obj);
}

void		free_scop(t_window_mgt *winmgt)
{
	if (winmgt != NULL)
	{
		if (winmgt->obj != NULL)
			free_obj(winmgt->obj);
		if (winmgt->ms != NULL)
		{
			if (winmgt->ms->model != NULL)
				mat4_free(winmgt->ms->model);
			if (winmgt->ms->view != NULL)
				mat4_free(winmgt->ms->view);
			if (winmgt->ms->projection != NULL)
				mat4_free(winmgt->ms->projection);
			free(winmgt->ms);
		}
		free(winmgt);
	}
}

void		write_usage(void)
{
	printf("Usage: ./scop <-v INT.INT> <-w INT> <-h INT> <-r INT> <-f>");
	printf("PATH_TO_OBJ <-t> TEXT_FILE_NAME\n\n");
	printf("Optionnal parameters:\n");
	printf("\t-v (aka --version): Default: 4.1\n\t\tAvailable versions: ");
	printf("3.3, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6\n\t\t");
	printf("Specify OpenGL version.\n\n");
	printf("\t-w (aka --width): MIN: %d MAX: %d Default: %d\n\t\t", \
	WIDTH_MIN, WIDTH_MAX, WIDTH_DEFAULT);
	printf("Set window width.\n\n");
	printf("\t-w (aka --height): MIN: %d MAX: %d Default: %d\n\t\t", \
	HEIGHT_MIN, HEIGHT_MAX, HEIGHT_DEFAULT);
	printf("Set window height.\n\n");
	printf("\t-r (aka --refresh-rate): MIN: %d MAX: %d ", \
	REFRESH_RATE_MIN, REFRESH_RATE_MAX);
	printf("Default: monitor refresh rate\n\t\tOverwrite refresh rate\n\n");
	printf("\t-f (aka --fullscreen)\n\t\tSet fullscreen mode.\n\n");
	printf("\t-t (aka --texture)\n\t\tSpecify texture name to use ");
	printf("(texture must be in .bmp and in textures folder)\n\n");
	printf("Mandatory parameters:\n");
	printf("\tPATH_TO_OBJ:\n\t\tPath to Wavefront .obj file\n");
}
