/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:58 by jjaouen           #+#    #+#             */
/*   Updated: 2020/06/23 09:54:46 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool			is_valid_file(char *path)
{
	int			fd;
	char		*format;
	int			s_size;

	s_size = strlen(path);
	fd = open(path, O_RDONLY);
	if (fd < 1 || s_size < 5)
	{
		puts("Error: File not found.\n");
		return (false);
	}
	format = ft_strsub(path, s_size - 4, 4);
	if (strcmp(format, ".obj"))
	{
		puts("Error: Input must be a .obj file.\n");
		free(format);
		close(fd);
		return (false);
	}
	free(format);
	close(fd);
	return (true);
}

char			*get_string_file(char *path)
{
	char		*buffer;
	int			ret;
	FILE		*f;
	int			length;

	length = 0;
	ret = 0;
	buffer = NULL;
	f = fopen(path, "rb");
	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length + 1);
		if (buffer)
			ret = fread(buffer, 1, length, f);
		else
			return (fclose(f) == 0 ? NULL : NULL);
		if (ret == 0)
			return (fclose(f) == 0 ? NULL : NULL);
		fclose(f);
	}
	buffer[length] = '\0';
	return (buffer);
}

void			edit_shaders_version(t_window_mgt **winmgt, char *shader_text)
{
	char		*c;

	c = NULL;
	if ((*winmgt)->custom_version)
	{
		c = ft_itoa((*winmgt)->major);
		shader_text[9] = c[0];
		free(c);
		c = ft_itoa((*winmgt)->minor);
		shader_text[10] = c[0];
		free(c);
	}
}

char			*get_path(char *name)
{
	char		*file;

	file = ft_strnew(strlen(SHADER_PATH) + strlen(name));
	file = ft_strcpy(file, SHADER_PATH);
	file = ft_strcat(file, name);
	return (file);
}

char			*get_shader(t_window_mgt **winmgt, char *name)
{
	int			fd;
	char		*file;
	char		*shader_text;
	char		*line;

	shader_text = NULL;
	line = NULL;
	file = get_path(name);
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		free(file);
		clean_glfw((*winmgt), "Shader not found.\n");
		exit(3);
	}
	while (get_next_line(fd, &line))
	{
		shader_text = (shader_text == NULL ? ft_strdup(line) : \
		ft_strjoinf(shader_text, line, 2));
		shader_text = ft_strjoinf(shader_text, "\n", 1);
	}
	close(fd) ? NULL : free(file);
	edit_shaders_version(winmgt, shader_text);
	return (shader_text);
}
