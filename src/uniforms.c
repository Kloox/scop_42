/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniforms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:33 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/11 21:41:30 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				set_uniform_mvp(t_window_mgt **winmgt)
{
	float			mvp2[4][4];
	float			**vp1;
	float			**mvp1;

	vp1 = mat4_init(0.f);
	mvp1 = mat4_init(0.f);
	(*winmgt)->cam.angle += (1.0f / (*winmgt)->refresh_rate);
	if ((*winmgt)->cam.angle > 2 * M_PI)
		(*winmgt)->cam.angle = 0.f;
	mat4_mult(vp1, (*winmgt)->ms->projection, (*winmgt)->ms->view);
	mat4_mult(mvp1, (*winmgt)->ms->model, vp1);
	if (!(*winmgt)->sleep)
		rotate_y(mvp1, mvp1, (*winmgt)->cam.angle);
	memcpy(mvp2[0], mvp1[0], sizeof(float) * 4);
	memcpy(mvp2[1], mvp1[1], sizeof(float) * 4);
	memcpy(mvp2[2], mvp1[2], sizeof(float) * 4);
	memcpy(mvp2[3], mvp1[3], sizeof(float) * 4);
	set_uniform_mat4((*winmgt)->gl_state.shader_program, "mvp", mvp2);
	mat4_free(mvp1);
}

t_texture_file		*check_text_file(FILE *fd, t_texture_file *tf)
{
	if (!fd)
	{
		printf("Error: Texture not found.\n");
		free(tf);
		return (NULL);
	}
	tf->header = (unsigned char *)ft_memallocexit(sizeof(char) * 54);
	tf->header = (unsigned char *)memset(tf->header, 0, sizeof(char) * 54);
	if (fread(tf->header, 1, 54, fd) != 54 || \
		(tf->header[0] != 'B' || tf->header[1] != 'M'))
	{
		printf("Not a correct BMP file\n");
		return (NULL);
	}
	tf->data_pos = *(unsigned int *)&tf->header[0x0A];
	tf->image_size = *(unsigned int *)&tf->header[0x22];
	tf->width = *(unsigned int *)&tf->header[0x12];
	tf->height = *(unsigned int *)&tf->header[0x16];
	if (tf->image_size == 0)
		tf->image_size = tf->width * tf->height * 3;
	if (tf->data_pos == 0)
		tf->data_pos = 54;
	tf->data = (unsigned char *)ft_memallocexit(sizeof(char) * tf->image_size);
	return (tf);
}

t_texture_file		*get_file_texture(char *name)
{
	t_texture_file	*tf;
	char			*file;
	FILE			*fd;
	int				ret;
	const char		path[31] = TEXTURE_PATH;

	file = NULL;
	ret = 0;
	tf = ft_memallocexit(sizeof(t_texture_file));
	tf = memset(tf, 0, sizeof(t_texture_file));
	file = ft_strnew(ft_strlen(path) + ft_strlen(name));
	file = ft_strcpy(file, path);
	file = ft_strcat(file, name);
	fd = fopen(file, "rb");
	free(file);
	if (check_text_file(fd, tf) == NULL)
		return (NULL);
	ret = fread(tf->data, 1, tf->image_size, fd);
	if (ret == 0)
	{
		fclose(fd);
		return (NULL);
	}
	fclose(fd);
	return (tf);
}
